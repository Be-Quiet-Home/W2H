#ifndef W2H_APPLICATION_H
#define W2H_APPLICATION_H

#include <Application.h>


class W2HApplication : public BApplication {
public:
    W2HApplication();

    void ReadyToRun() override;
};


#endif
