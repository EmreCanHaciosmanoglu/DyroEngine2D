#ifndef _DELETEMACRO_H
#define _DELETEMACRO_H

//Defines
#define SafeRelease(x) { if(x) {x->Release(); x = nullptr;} else {__asm { int 3 };} } // Macro for releasing COM object, if already released trigger breakpoint
#define SafeDelete(x) { if(x) {delete x; x = nullptr;} else {__asm { int 3 };} } // Macro for deleting objects, if already released trigger breakpoint

#endif