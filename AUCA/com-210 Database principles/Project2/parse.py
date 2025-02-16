from bs4 import BeautifulSoup
import urllib2
import re



def getTitle(s):
	return s[:-6], s[-6:]

def getTime(s):
	return  s[:2]

def getQuantity(s):
	#print s
	end = s[-4:]
	result = ''.join([i for i in end if not i.isdigit()])

	
	dig = ''.join([i for i in s if i.isdigit()])
	return dig, result
		
			
def Parse(w, N):
	mas = []
	zCounter = 0
	pageNum = 0
	while pageNum < N:
		if(w == "Globus"): #Globus
			url = 'https://globus.kg/action-products/products?page=' + str(pageNum)
		else: #Narodnyi
			url = 'https://www.market.kg/action-products/products?page=' + str(pageNum)
		try:
		    page = urllib2.urlopen(url).read()
		 
		except:
		    print("An error occured. can not open url!")


		soup = BeautifulSoup(page, 'html.parser')
		
		

		regex = re.compile('^tocsection-')
		product_title = soup.find_all('h3', attrs={'class': "product__item__title"})
		price__old = soup.find_all('span', attrs={'class': "price__old__summ"})
		price__fresh = soup.find_all('div', attrs={'class': "price__sum"})
		sale__time = soup.find_all('span', attrs={'class': "sale__time_hours"})
			
		for i in range(30):
		    content = []
		    name, quantity_per = getTitle(product_title[i].getText().strip())
		    content.append(w)
		    content.append(name)
		    q = getQuantity(quantity_per)
		    content.append(q[0])
		    content.append(q[1])
		    content.append(price__old[i].getText())
		    content.append(price__fresh[i].getText())
		    content.append(getTime(sale__time[i].getText()).rstrip())
		    #mas.append(content)
		    mas.append(content)	   
		    zCounter += 1
		   
		pageNum += 1
	
	return mas



