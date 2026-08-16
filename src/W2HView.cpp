#include "W2HView.h"

#include "Messages.h"

#include <Font.h>
#include <InterfaceDefs.h>
#include <Message.h>
#include <Window.h>


W2HView::W2HView(BRect frame)
    :
    BView(
        frame,
        "w2h-view",
        B_FOLLOW_ALL,
        B_WILL_DRAW | B_NAVIGABLE),
    fInputObserved(false)
{
    SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
}


void
W2HView::Draw(BRect updateRect)
{
    (void)updateRect;

    SetHighColor(ui_color(B_PANEL_TEXT_COLOR));

    BFont font;
    GetFont(&font);

    font_height metrics = {};
    font.GetHeight(&metrics);

    const char* label = "W2H";
    const float textWidth = font.StringWidth(label);
    const BRect bounds = Bounds();

    const float x
        = bounds.left + (bounds.Width() - textWidth) / 2.0f;

    const float y
        = bounds.top
        + (bounds.Height() + metrics.ascent - metrics.descent) / 2.0f;

    DrawString(label, BPoint(x, y));

    if (fInputObserved) {
        const float underlineY = y + 6.0f;

        StrokeLine(
            BPoint(x, underlineY),
            BPoint(x + textWidth, underlineY));
    }
}


void
W2HView::KeyDown(const char* bytes, int32 numBytes)
{
    BWindow* window = Window();

    if (window != nullptr) {
        BMessage message(kMsgInputObserved);

        if (window->PostMessage(&message) == B_OK)
            return;
    }

    BView::KeyDown(bytes, numBytes);
}


void
W2HView::NoteInput()
{
    if (fInputObserved)
        return;

    fInputObserved = true;
    Invalidate();
}
