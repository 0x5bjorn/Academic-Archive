#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Button
{
    public:
    
    typedef void (*Action)(Button&);
    
    Button(const string& aTxt, 
           int aX, int aY, int aW, int aH, Action anAct)
    : txt(aTxt), x(aX), y(aY), w(aW), h(aH), act(anAct)
    {
    }
    
    bool isClicked(int ax, int ay) const
    {
        bool bx = x <= ax and ax <= x + w;
        bool by = y <= ay and ay <= y + h;
        
        return bx and by;
    }
    
    void doOnClick()
    {
        act(*this);
    }
    
    const string&  getText() const
    {
        return txt;
    }
    
    private:
    
    string txt;
    
    int x;
    int y;
    int w;
    int h;
        
    Action act;
};

void hTitle(Button& b)
{
    cout << "I am the main button" << endl;
}

void hShowTitle(Button& b)
{
    cout << "You clicked on button " << b.getText() << endl;
}

int main()
{
    vector<Button> buttons;
    
    buttons.emplace_back("Title", 350, 10, 100, 40, hTitle);
    buttons.emplace_back("Left", 10, 400, 100, 40, hShowTitle);
    buttons.emplace_back("Button", 700, 400, 100, 40, hShowTitle);

    int x;
    int y;
    while (cin >> x >> y)
    {
        for (auto& b: buttons)
        {
            if (b.isClicked(x, y))
            {
                b.doOnClick();
            }
        }
    }
        
    return 0;
}