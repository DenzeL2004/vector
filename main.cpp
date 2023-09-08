#include <stdio.h>

#include "src/graphic/graphic.h"
#include "src/graphic/graphic_config.h"

int main()
{
     #ifdef USE_LOG
        if (OpenLogsFile()) 
            return OPEN_FILE_LOG_ERR;
    #endif


    ShowWindow(Example_vectors, Count_example_vec);

    #ifdef USE_LOG
        if (CloseLogsFile ())
            return OPEN_FILE_LOG_ERR;
    #endif

    return EXIT_SUCCESS;
}