#ifndef W2H_VIEW_H
#define W2H_VIEW_H

#include <View.h>


class W2HView : public BView {
public:
    explicit W2HView(BRect frame);

    void Draw(BRect updateRect) override;
    void KeyDown(const char* bytes, int32 numBytes) override;

    void NoteInput();

private:
    bool fInputObserved;
};


#endif
