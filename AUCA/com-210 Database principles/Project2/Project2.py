import MySQLdb, sys, os, datetime
import parse as Parse

#-----Database connection class----------------
class DbConnection:
    def __init__(self):
        self.conn = MySQLdb.connect("localhost", "sultan", "mysql", "sultan")
        self.cursor = self.conn.cursor()

    def close(self):
        self.db.close()

#-----FUNCTIONS-------------------------------------------
def get_user_option():
    print("\n[mm] Start making menu.")
    print("[rp] Start recording purchase.")
    print("[sm] Show menu.")
    print("[so] Show OnSale information of specific product.")
    print("[q] Quit.")
    return(raw_input("Choose option: "))

# list of meal types (breakfast...)
def get_mealTypes(db):
    db.cursor.execute("select type_name from MealTypes")
    mealTypes = []
    print("\n---Types of meal---")
    for row in db.cursor.fetchall():
        mealTypes.append(row[0])
        print row[0]
    print("\n"),

    mealTypeInput = ''
    while mealTypeInput not in mealTypes:
        mealTypeInput = raw_input("Choose type of meal: ")

    return mealTypeInput

# list of meals
def get_meal(db, mealTypeInput):
    query = "select m.meal_name from Meals m join MealTypes mt on m.mealType_id = mt.type_id where mt.type_name = %s"
    db.cursor.execute(query, [mealTypeInput])
    meals = []
    print("\n---List of meal---")
    for row in db.cursor.fetchall():
        meals.append(row[0])
        print row[0]
    print("\n"),

    mealInput = ''
    while mealInput not in meals:
        mealInput = raw_input("Choose meal: ")

    return mealInput

# list of recipes
def get_recipe(db, mealInput):
    query = "select r.recipe_name from Recipes r join Meals m on r.meal_id = m.meal_id where m.meal_name = %s"
    db.cursor.execute(query, [mealInput])
    recipes = []
    print("\n---List of recipes---")
    for row in db.cursor.fetchall():
        recipes.append(row[0])
        print row[0]
    print("\n"),

    recipeInput = ''
    while recipeInput not in recipes:
        recipeInput = raw_input("Choose recipe: ")

    return recipeInput

# recipe details
def show_recipe_details(db, recipeInput, onSaleResults):
    query = """select p.product_name, rd.product_quantity, mst.measureType_name, r.instruction from Recipes r
                                join RecipeDetails rd on r.recipe_id = rd.recipe_id
                                join Products p on p.product_id = rd.product_id
                                join MeasurementTypes mst on rd.measure_id = mst.measure_id
                                where r.recipe_name = %s"""
    db.cursor.execute(query, [recipeInput])
    print("\n---Recipe details---")
    intruct = ""
    productNames = []
    for row in db.cursor.fetchall():
        productNames.append(str(row[0]))
        print str(row[0]).ljust(30), str(row[1]).rjust(5), str(row[2]).rjust(15)
        instruct = row[3]

    query = """Select p.product_name, p.quantity_inStorage, mst.measureType_name from Products p
                join MeasurementTypes mst on p.measure_id = mst.measure_id
                where p.product_name = %s"""
    print("\n---Quantity in storage---")
    for pn in productNames:
        db.cursor.execute(query, [pn])
        for row in db.cursor.fetchall():
            print str(row[0]).ljust(30), str(row[1]).rjust(5), str(row[2]).rjust(15)
    print("\n"),

    print("Instruction: ")
    print instruct

    print("\n"),
    onSaleOptionInput = ""
    while onSaleOptionInput != "yes" and onSaleOptionInput != "no":
        onSaleOptionInput = raw_input("---See onSale information of the specific product(yes) or not(no): ")

    if onSaleOptionInput == "yes":
        show_onSale_info(db, productNames, onSaleResults)

# see OnSale info of product
def show_onSale_info(db, productNames, onSaleResults):
    print("\n[leave] Leave OnSale information search mode.")
    productInput = ""
    while productInput != "leave":
        while productInput not in productNames:
            productInput = raw_input("Choose product: ")
            if productInput == "leave":
                break

            if productInput != "leave":
                query = """Select s.quantity, mst.measureType_name, s.base_price_per_quantity, s.onSale_price_per_quantity, sh.shop_name, s.valid_from, s.valid_until from Sale s
                            join Products p on s.product_id = p.product_id
                            join MeasurementTypes mst on s.measure_id = mst.measure_id
                            join Shops sh on s.shop_id = sh.shop_id
                            where p.product_name = %s"""
                db.cursor.execute(query, [productInput])
                for row in db.cursor.fetchall():
                    print str(row[0]).rjust(10), str(row[1]).rjust(10), (str(row[2])+" base price").rjust(20), (str(row[3])+" onSale price").rjust(20), str(row[4]).rjust(10), str(row[5]).rjust(11), str(row[6]).rjust(11)
                print("\n"),
            productInput = ""

# insert Cooking details
def insert_cookingDetails(db, mealInput, mealTypeInput):
    query = "select chef_name from Chefs"
    db.cursor.execute(query)
    print("\n---Chefs---")
    chefNames = []
    for row in db.cursor.fetchall():
        chefNames.append(row[0])
        print row[0]
    chefInput = ""
    while chefInput not in chefNames:
        chefInput = raw_input("Write chef name: ")

    dateInput = raw_input("Write date (YYYY-MM-DD): ")
    query = """Insert into CookingDetails set chef_id = (select chef_id from Chefs where chef_name = %s),
            meal_id = (select m.meal_id from Meals m join MealTypes mt on m.mealType_id = mt.type_id where m.meal_name = %s and mt.type_name = %s),
            date = %s"""
    db.cursor.execute(query, [chefInput, mealInput, mealTypeInput, dateInput])

# show menu
def show_menu(db):
    searchOptionInput = ""
    while searchOptionInput != 'd' and searchOptionInput != 'n':
            searchOptionInput = raw_input("---Show by date(d) or by name(n)?: ")

    if searchOptionInput == 'd':
        dateInput = raw_input("Date: ")
        query = """Select mt.type_name, ch.chef_name, m.meal_name from CookingDetails cd
                    join Chefs ch on cd.chef_id = ch.chef_id
                    join Meals m on cd.meal_id = m.meal_id
                    join MealTypes mt on m.mealType_id = mt.type_id
                    where cd.date = %s"""
        db.cursor.execute(query, [dateInput])

    elif searchOptionInput == 'n':
        nameInput = raw_input("Name: ")
        query = """Select mt.type_name, cd.date, m.meal_name from CookingDetails cd
                    join Chefs ch on cd.chef_id = ch.chef_id
                    join Meals m on cd.meal_id = m.meal_id
                    join MealTypes mt on m.mealType_id = mt.type_id
                    where ch.chef_name = %s"""
        db.cursor.execute(query, [nameInput])

    if db.cursor.rowcount != 0:
        print("\n-------------------------------------------------")
        for row in db.cursor.fetchall():
            print str(row[0]).ljust(10), str(row[1]).rjust(10), str(row[2]).rjust(10)
        print("-------------------------------------------------")
    else:
        print("\n-----------------ERROR-------------------")

# record purchase
def record_purchase(db):
    try:
        productNames = []
        query = "select product_name from Products"
        db.cursor.execute(query)
        for row in db.cursor.fetchall():
            productNames.append(row[0])

        productInput = raw_input("Product name: ")
        if productInput not in productNames:
            productTypes = []
            query = "select type_name from ProductTypes"
            db.cursor.execute(query)
            print("\n---Product types---")
            for row in db.cursor.fetchall():
                productTypes.append(row[0])
                print row[0]
            productTypeInput = ''
            while productTypeInput not in productTypes:
                productTypeInput = raw_input("Type of measurement: ")

        quantityInput = raw_input("Purchased quantity: ")

        measurementTypes = []
        query = "select measureType_name from MeasurementTypes"
        db.cursor.execute(query)
        print("\n---Measurement types---")
        for row in db.cursor.fetchall():
            measurementTypes.append(row[0])
            print row[0]
        measurementInput = ''
        while measurementInput not in measurementTypes:
            measurementInput = raw_input("Type of measurement: ")

        if productInput not in productNames:
            query = """Insert into Products set product_name = %s,
                        productType_id = (select type_id from ProductTypes where type_name= %s),
                        quantity_inStorage = %s,
                        measure_id = (select measure_id from MeasurementTypes where measureType_name = %s)"""
            db.cursor.execute(query, [productInput, productTypeInput, float(quantityInput), measurementInput])
        else:
            query = "Update Products set quantity_inStorage = quantity_inStorage + %s where product_name = %s"
            db.cursor.execute(query, [float(quantityInput), productInput])

        priceInput = raw_input("Price for purchased quantity: ")

        shopNames = []
        query = "select shop_name from Shops"
        db.cursor.execute(query)
        print("\n---Shop names---")
        for row in db.cursor.fetchall():
            shopNames.append(row[0])
            print row[0]
        shopInput = ''
        while shopInput not in shopNames:
            shopInput = raw_input("Shop name: ")

        dateInput = raw_input("Purchase date: ")

        query = """Insert into PurchaseRecords set product_id = (select product_id from Products where product_name = %s),
                    measure_id = (select measure_id from MeasurementTypes where measureType_name = %s),
                    shop_id = (select shop_id from Shops where shop_name = %s),
                    purchased_quantity = %s,
                    price_for_purchased_quantity = %s,
                    date_purchased = %s"""
        db.cursor.execute(query, [productInput, measurementInput, shopInput, float(quantityInput), float(priceInput), dateInput])
        print "---Purchase was successfully recorded.---"
        db.conn.commit()
    except:
        print("\n|----------------------ERROR-------------------------|")
        print("|---------------Transaction failure------------------|")
        print("|----------------------------------------------------|")

        db.conn.rollback()

# fill Sale information
# *********************************************************************************************
# Did not manage to import parsed data to database.
# There are lots of invalid results come from parsing (for example, letter and number are set in chaos order)
# There is also problem with languages. It store in russian language, but the app shows some sings, symbols etc.
# ******************************************************************************************************
def parse_site(db, onSaleResults):
    for onSale in onSaleResults:
        onSaleInformation = []
        query = "Select p.product_name from Sale s join Products p where s.product_id = p.product_id"
        db.cursor.execute(query)
        for row in db.cursor.fetchall():
            onSaleInformation.append(row[0])
        try:
            today = datetime.datetime.today()
            shopName = onSale[0].strip()
            productName = onSale[1].encode('utf8','ignore')
            quantity = float(onSale[2])
            measureName = onSale[3].encode('utf8','ignore').strip()
            basePrice = float(onSale[4])
            onSalePrice = float(onSale[5])
            validFrom = str(today.year)+"-"+str(today.month)+"-"+str(today.day)
            validUntil = str(today.year)+"-"+str(today.month)+"-"+str(today.day + int(onSale[6]))

            if productName not in onSaleInformation:
                query = """Insert into Sale set product_id = (select product_id from Products where product_name = %s),
                                                 measure_id = (select measure_id from MeasurementTypes where measureType_name = %s),
                                                 shop_id = (select shop_id from Shops where shop_name = %s),
                                                 quantity = %s, base_price_per_quantity = %s,
                                                 base_price_per_quantity = %s,
                                                 onSale_price_per_quantity = %s, valid_from = %s, valid_until = %s"""

                db.cursor.execute(query, [productName, measureName, shopName, float(quantity), float(basePrice), float(onSalePrice), validFrom, validUntil])
            else:
                query = """Update Sale set product_id = (select product_id from Products where product_name = %s),
                                             measure_id = (select measure_id from MeasurementTypes where measureType_name = %s),
                                             shop_id = (select shop_id from Shops where shop_name = %s),
                                             quantity = %s, base_price_per_quantity = %s,
                                             base_price_per_quantity = %s,
                                             onSale_price_per_quantity = %s, valid_from = %s, valid_until = %s"""

                db.cursor.execute(query, [productName, measureName, shopName, float(quantity), float(basePrice), float(onSalePrice), validFrom, validUntil])
            db.conn.commit()
        except:
            print("\n|----------------------ERROR-------------------------|")
            print("|---------------Transaction failure------------------|")
            print("|----------------------------------------------------|")

            db.conn.rollback()

# -----MAIN-----------------------------------------------
def main(onSaleResults):
    db = DbConnection()

    # parse_site(db, onSaleResults)

    optionInput = ''
    while optionInput != 'q':

        optionInput = get_user_option()

        if optionInput == "mm":
            try:
                # list of meal types (breakfast...)
                mealTypeInput = get_mealTypes(db)
                # list of meals
                mealInput = get_meal(db, mealTypeInput)
                # list of recipes
                recipeInput = get_recipe(db, mealInput)
                # recipe details
                show_recipe_details(db, recipeInput, onSaleResults)
                # choose date and chef
                insert_cookingDetails(db, mealInput, mealTypeInput)

                db.conn.commit()
            except:
                print("\n|----------------------ERROR-------------------------|")
                print("|---------------Transaction failure------------------|")
                print("|----------------------------------------------------|")

                db.conn.rollback()

        elif optionInput == "sm":
            show_menu(db)

        elif optionInput == "so":
            productNames = []
            query = "select product_name from Products"
            db.cursor.execute(query)
            print("\n---List of products---")
            for row in db.cursor.fetchall():
                productNames.append(row[0])
                print row[0]
            show_onSale_info(db, productNames, onSaleResults)

        elif optionInput == "rp":
            record_purchase(db)

        elif optionInput == 'q':
            print("Have a nice day.")
            sys.exit(-1)
        else:
            print("\nWrong option.")
            continue

    db.conn.close()

if __name__ == "__main__":
    onSaleResults = Parse.Parse("Globus", 6)

    main(onSaleResults)
