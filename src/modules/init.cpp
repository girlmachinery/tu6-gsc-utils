#include "stdinclude.h"
#include "modules/gsc/loading.h"
#include "modules/gsc/function.h"
#include "modules/gsc/method.h"

#include "init.h"

namespace init
{
    void init()
    {
        gsc::loading::init();
        gsc::function::init();
        gsc::method::init();

    }

    void unload()
    {
        gsc::loading::unload();
        gsc::function::unload();
        gsc::method::unload();
    }
}
