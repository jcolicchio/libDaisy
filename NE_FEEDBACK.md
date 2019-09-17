
Stephen's feedback upon useage of libdaisy for the benefit of the users.

 - The headers are not C++ compatible, need the standard #ifdef __cplusplus / extern "C" { wrappers
 - libdaisy.h is included with <> even though its in the same directory. This is safer to use "" as it doesn't depend on compiler settings or compiler include behavior. please dont _ever_ separate your include files from your source files. 
 - why not pass the audio callback to dsy_audio_init? not sure you would ever not want to set the callback if you are initing it. You can set a default argumen to empty(). Or not as you are C not C++ :( Also if the callback is specified in init you can also start the audio in one call rather than three. This seems like the typical use case rather than spreading this out across three calls.
 - audio sample rate should be configurable in code (this is stupidly hard to do well with cube but really easy setting the registers directly if you know the SAI input clock hz)
 - #pragma once is your friend
 - defining DMA1_Stream0_IRQHandler conflicts with a default cube generated project as HAL has its own internal definition of this (gonna be tricky to fix this cleanly you probaly need to overwrite the IRQ vector  with your differently named function since this function is technically dynamicly linked: g_pfnVectors[vector] = my_dma_callback;) -- just commenting these out in dsy_audio.c solves the problem. Not sure why there are different versions of this function about.
 - dsy_sdram_init should return the ram size and a pointer to the base address. Or this should be queryiable through another interface to support applications that don't use link time management of this memory block.
 - having return codes for initialization functions seems kind of silly.. If something fails intentionally crashing is usually a cleaner way to communicate the failure as you can't ignore that accidently which is pretty much the default behavior if you dont crash (no one ever checks the return values of init stuff)
 
 