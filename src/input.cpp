#include "szg_c.h"

#include <string>

#define PRINT_ERROR(x)


// arNetInputSource

arNetInputSource* szgNetInput() {
    return new arNetInputSource();
}

void szgNetInput_delete( arNetInputSource* nis ) {
    if (nis == NULL) {
        PRINT_ERROR( "szgNetInput_delete() passed NULL pointer" );
        return;
    }
    delete nis;
}

// Only use ONE OR THE OTHER of these two!
bool szgNetInput_setSlot( arNetInputSource* nis, unsigned int slot ) {
    return nis->setSlot( slot );
}
bool szgNetInput_setServiceName( arNetInputSource* nis, const char* name ) {
    return nis->setServiceName( std::string(name) );
}

bool szgNetInput_connected( arNetInputSource* nis ) {
    return nis->connected();
}



// arInputNode

arInputNode* szgInputNode( bool bufferEvents ) {
    return new arInputNode( bufferEvents );
}

void szgInputNode_delete( arInputNode* nod ) {
    if (nod == NULL) {
        PRINT_ERROR( "szgInputNode_delete() passed NULL pointer" );
        return;
    }
    delete nod;
}

void szgInputNode_addInputSource( arInputNode* nod, arNetInputSource* src, bool iOwnIt ) {
    return nod->addInputSource( src, iOwnIt );
}

bool szgInputNode_init( arInputNode* nod, arSZGClient* cli ) {
    return nod->init( *cli );
}

bool szgInputNode_start( arInputNode* nod ) {
    return nod->start();
}

bool szgInputNode_stop( arInputNode* nod ) {
    return nod->stop();
}

int szgInputNode_getNumberButtons( arInputNode* nod ) {
    return nod->getNumberButtons();
}

int szgInputNode_getNumberAxes( arInputNode* nod ) {
    return nod->getNumberAxes();
}

int szgInputNode_getNumberMatrices( arInputNode* nod ) {
    return nod->getNumberMatrices();
}

int szgInputNode_getButton( arInputNode* nod, int index ) {
    return nod->getButton( index );
}

float szgInputNode_getAxis( arInputNode* nod, int index ) {
    return nod->getAxis( index );
}

float* szgInputNode_getMatrix( arInputNode* nod, int index ) {
    arMatrix4 val = nod->getMatrix( index );
    float* ret = (float*)malloc( 16*sizeof(float) );
    memcpy( ret, val.v, 16*sizeof(float) );
    return ret;
}


