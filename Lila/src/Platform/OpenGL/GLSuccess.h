#pragma once

#include "Platform/Defines.h"
#include "Platform/Graphics.h"

namespace OpenGL {

    #define GL_SUCCESS  0
    #define GL_FAILED   1
    #define GL_HEADLESS 2
    
    /**
     * @brief A struct for OpenGL errors.
     * 
     * @param exitCode Type of exit code, 0 = Success, 1 = Failed, 2 = Headless.
     * @param flags Type of failure
     * 
    */
    struct GLSuccess {
        b8 exitCode;
        u32 flags;
    };

    /**
     * @brief A function for checking OpenGL errors.
     * 
     * @returns A GLSuccess report.
     * 
    */
    static GLSuccess checkErrors() {
        GLSuccess s;
    #ifdef LILA_OPENGL_CONTEXT
        u32 err = glGetError();
        
        if(err == GL_SUCCESS) {
            s.exitCode = GL_SUCCESS;
            s.flags = 0;
            return s;
        }
    
        s.exitCode = GL_FAILED;
        s.flags = err;
    #elif LILA_HEADLESS_CONTEXT
        s.exitCode = GL_HEADLESS;
        s.flags = 0;
    #else
        s.exitCode = GL_FAILED;
        s.flags = 1;
    #endif
        return s;
    }

    /**
     * @brief A function for checking if GLSuccess succeeded.
     * 
     * @returns A boolean.
     * 
    */
    static b8 isSuccess(GLSuccess s) {
        if(s.exitCode == GL_FAILED) {
            return false;
        }

        return true;
    }

} // namespace OpenGL