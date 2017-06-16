#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using namespace genv;


///////////////////////////////////////////////////
class ValamiButton;
class MyWindow;
typedef void(MyWindow::*m1fv_type)(void);


class MyWindow : public Window
{
public:


    StaticText *tx1;
    TextEditor *ed1;
    PushButton *button;
    ValamiButton * vButton;
    FvPtrButton * fvptrbutton;
    FunctorButton * functorbutton;

    Szambeallito *_szambeallito;

    MyWindow() ;
    void esemeny(string mitortent) {
        if (mitortent == "egyenlo") {
            tx1->setText(ed1->value());
        }
    }
    static void fv(Window *);
    void valami() {
        tx1->setText();
    }


};

class ValamiButton : public PushButton
{
    MyWindow * mywparent;

public:
    ValamiButton(MyWindow * parent, int x, int y, int sx,
                 int sy, std::string s)
        :PushButton(x, y, sx, sy, s)
    {
        mywparent = parent;

    }
    virtual void action() ;
};


MyWindow::MyWindow()
{

        _szambeallito = new Szambeallito(120,100,100,40,"functor",
                                          [this](){this->valami();});
        button = new MessageButton(this, 10, 10, 60, 60,"oda", "egyenlo");
        tx1 = new StaticText(75,20,100,40,"pipa");
        ed1 = new TextEditor(10,100,100,40,"editor");
        vButton = new ValamiButton(this, 10,200,100,40,"vbut");
        fvptrbutton = new FvPtrButton(this, 10,250,100,40,"fvptr",MyWindow::fv);
        functorbutton = new FunctorButton(10,300,100,40,"functor",
                                          [this](){this->valami();});
        widgets.push_back(_szambeallito);
        widgets.push_back(tx1);
        widgets.push_back(ed1);
        widgets.push_back(button);
        widgets.push_back(vButton);
        widgets.push_back(fvptrbutton);
        widgets.push_back(functorbutton );





}


void MyWindow::fv(Window *w) {
    MyWindow * mw = dynamic_cast<MyWindow*>(w);
    if (mw) {
        mw->valami();
    }
}

void ValamiButton::action()
{


     mywparent->valami();
}

int main()
{
    gout.open(400,400);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}
