#ifndef SZG_INPUT_H
#define SZG_INPUT_H

#include "arNetInputSource.h"
#include "arInputNode.h"


extern "C" {
    // arNetInputSource
    //
    arNetInputSource* EXPORT_API szgNetInput();

    void EXPORT_API szgNetInput_delete( arNetInputSource* nis );

    // Only use ONE OR THE OTHER of these two!
    bool EXPORT_API szgNetInput_setSlot( arNetInputSource* nis, unsigned int slot );
    bool EXPORT_API szgNetInput_setServiceName( arNetInputSource* nis, const char* name );

    bool EXPORT_API szgNetInput_connected( arNetInputSource* nis );
}    


extern "C" {
    // arInputNode
    //
    arInputNode* EXPORT_API szgInputNode( bool bufferEvents = false );
    void EXPORT_API szgInputNode_delete( arInputNode* nod );

    bool EXPORT_API szgInputNode_init( arInputNode* nod, arSZGClient* cli );
    bool EXPORT_API szgInputNode_start( arInputNode* nod );
    bool EXPORT_API szgInputNode_stop( arInputNode* nod );

    int EXPORT_API szgInputNode_getNumberButtons( arInputNode* nod );
    int EXPORT_API szgInputNode_getNumberAxes( arInputNode* nod );
    int EXPORT_API szgInputNode_getNumberMatrices( arInputNode* nod );

    int EXPORT_API szgInputNode_getButton( arInputNode* nod, int index );
    float EXPORT_API szgInputNode_getAxis( arInputNode* nod, int index );
    float* EXPORT_API szgInputNode_getMatrix( arInputNode* nod, int index );
}
#endif

