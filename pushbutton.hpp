#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "widgets.hpp"
#include "window.hpp"
#include <functional>

class PushButton : public Widget {
    std::string _felirat;
public:
    PushButton(int x, int y, int sx,
                int sy, std::string s);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual void action()=0;
};

class MessageButton : public PushButton {
    Window * _parent;
    std::string _azonosito;
public:
    MessageButton(Window * parent, int x, int y, int sx,
                int sy, std::string s, std::string azonosito);
    virtual void action();
};

class FvPtrButton : public PushButton {
    Window *_parent;
    void (*_fvmut)(Window *);
public:
    FvPtrButton (Window* parent, int x, int y, int sx,
                int sy, std::string s, void(*fvmut)(Window *));
    virtual void action();
};

class FunctorButton : public PushButton {
    std::function<void()> _functor;
public:
    FunctorButton(int x, int y, int sx,
                int sy, std::string s, std::function<void()> functor);
    void action();
};

class Szambeallito : public PushButton {
 std::function<void()> _functor;
public:
    Szambeallito(int x, int y, int sx,
                int sy, std::string s, std::function<void()> functor);
    void action();
};



#endif // PUSHBUTTON_HPP_INCLUDED
