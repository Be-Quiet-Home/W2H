#ifndef W2H_WINDOW_H
#define W2H_WINDOW_H

#include <Window.h>


class BView;
class W2HView;


class W2HWindow : public BWindow {
public:
    W2HWindow();

    void MessageReceived(BMessage* message) override;

private:
    BView* fDesktopView;
    W2HView* fView;
};


#endif
