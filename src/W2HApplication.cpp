#include "W2HApplication.h"

#include "W2HWindow.h"


namespace {

constexpr const char* kApplicationSignature
    = "application/x-vnd.BeQuietHome-W2H";

}


W2HApplication::W2HApplication()
    :
    BApplication(kApplicationSignature)
{
}


void
W2HApplication::ReadyToRun()
{
    W2HWindow* window = new W2HWindow();
    window->Show();
}
