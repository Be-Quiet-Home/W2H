#include "W2HWindow.h"

#include "Messages.h"
#include "W2HView.h"


W2HWindow::W2HWindow()
    :
    BWindow(
        BRect(100.0f, 100.0f, 620.0f, 360.0f),
        "W2H",
        B_TITLED_WINDOW,
        B_QUIT_ON_WINDOW_CLOSE),
    fView(new W2HView(Bounds()))
{
    AddChild(fView);
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
