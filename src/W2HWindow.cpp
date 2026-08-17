#include "W2HWindow.h"

#include "Messages.h"
#include "W2HView.h"

#include <View.h>


W2HWindow::W2HWindow()
    :
    BWindow(
        BRect(100.0f, 100.0f, 620.0f, 360.0f),
        "W2H",
        B_TITLED_WINDOW,
        B_QUIT_ON_WINDOW_CLOSE),
    fDesktopView(new BView(
        Bounds(),
        "w2h-desktop",
        B_FOLLOW_ALL,
        0)),
    fView(new W2HView(fDesktopView->Bounds()))
{
    AddChild(fDesktopView);
    fDesktopView->AddChild(fView);
    fView->MakeFocus(true);
}


void
W2HWindow::MessageReceived(BMessage* message)
{
    if (message->what == kMsgInputObserved) {
        fView->NoteInput();
        return;
    }

    BWindow::MessageReceived(message);
}
