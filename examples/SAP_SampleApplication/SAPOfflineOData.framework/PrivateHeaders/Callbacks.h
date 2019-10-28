//
//  Callbacks.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "EnumerationDef.h"
#import "lodatatestcallbacks.hpp"
#import "logobservercallbacks.hpp"
#import "openobservercallbacks.hpp"
#import "statechangecallback.hpp"
#import "store.hpp"
#import "ulsynchelper.h"
#import "sendstoreprogressobservercallbacks.hpp"

using namespace lodata;
namespace lodata {
    class Error;
	class ModifyRequestFailure;
}

@class StoreWrapper;

typedef void(^CompletionBlock)(BOOL,NSError*);

class OpenObserverCallbackImpl : public OpenObserverCallbacks {
private:
    __weak StoreWrapper* _storeWrapper;
    
public:
    OpenObserverCallbackImpl(StoreWrapper* storeWrapper) {this->_storeWrapper = storeWrapper;}
    void Notification( StoreNotification notification );
    void UpdateSyncProgress( ProgressStatus progress );
};

class StateChangeCallbackImpl : public StateChangeCallback {
private:
    __weak StoreWrapper* _storeWrapper;
    
public:
    StateChangeCallbackImpl(StoreWrapper* storeWrapper) {this->_storeWrapper = storeWrapper;}
    void StateChanged( Store::State state );
};

class RefreshProgressCallbackImpl : public SyncProgressObserverCallbacks {
private:
    __weak StoreWrapper* _storeWrapper;
    
public:
    RefreshProgressCallbackImpl(StoreWrapper* storeWrapper) {this->_storeWrapper = storeWrapper;}
    
    void UpdateSyncProgress( ProgressStatus progress );
};

class FlushQueueProgressCallbackImpl : public SyncProgressObserverCallbacks {
private:
    __weak StoreWrapper* _storeWrapper;
    
public:
    FlushQueueProgressCallbackImpl(StoreWrapper* storeWrapper) {this->_storeWrapper = storeWrapper;}
    void UpdateSyncProgress( ProgressStatus progress );
    void requestFailureCallback( StoreWrapper* store, ModifyRequestFailure * cRequestFailure );
};

class SendStoreProgressObserverCallbackImpl : public SendStoreProgressObserverCallbacks {
private:
    __weak StoreWrapper* _storeWrapper;

public:
    SendStoreProgressObserverCallbackImpl( StoreWrapper* storeWrapper ) {this->_storeWrapper = storeWrapper;}
    void UpdateSendStoreProgress( SendStoreProgressStatus progress );
};

class LogCallbackImpl: public LogObserverCallbacks {
private:
    __weak StoreWrapper * _storeWrapper;

public:
    LogCallbackImpl( StoreWrapper * storeWrapper ) { this->_storeWrapper = storeWrapper; }
    ClientLogLevel GetClientLogLevel();
    void Log( ClientLogLevel cll, const char * message );
};

#if DEBUG
typedef NSInteger(^TestCallbacks)(NSInteger , NSInteger);

class LODataTestCallbackImpl : public LODataTestCallbacks
{

private:
    __weak StoreWrapper* _storeWrapper;
      TestCallbacks _myTestCallback = NULL;
    
public:
    LODataTestCallbackImpl(StoreWrapper* storeWrapper,TestCallbacks myTestCallback ) {
        this->_storeWrapper = storeWrapper;
        this->_myTestCallback = myTestCallback;

    }
    bool Notify( LODataContext context, void * data )
    {
        switch (context)
        {
			case LODATA_TEST_SYNC_OBSERVER:
            {
                ULSyncHelper * handler = (ULSyncHelper * ) data;
                ULSyncHelper::stats_t stats;

                handler->GetStats(&stats);

                ULSyncState state;

                switch( stats.state )
                {
                    case ULSyncHelper::CONNECTING:
                        state = ULSYNC_CONNECTING;
                        break;
                    case ULSyncHelper::PROCESSING:
                        state = ULSYNC_PROCESSING;
                        break;
                    case ULSyncHelper::WAITING:
                        state = ULSYNC_WAITING;
                        break;
                    case ULSyncHelper::SENDING:
                        state = ULSYNC_SENDING;
                        break;
                    case ULSyncHelper::RECEIVING:
                        state = ULSYNC_RECEIVING;
                        break;
					case ULSyncHelper::DONE:
                        state = ULSYNC_DONE;
						break;
					case ULSyncHelper::NOT_SYNCHRONIZING:
                        state = ULSYNC_NOT_SYNCHRONIZING;
						break;
					case ULSyncHelper::DOWNLOADING:
						// This is a background download.  This will be continued to return about once a second
						// while a background sync is in progress.
                        state = ULSYNC_DOWNLOADING;
						break;
                }

                NSInteger functionCall = this->_myTestCallback(LODataContextObjC::LODATA_TEST_SYNC_OBSERVER_OBJC, state);

                if( functionCall == 0 ) { // This return value is for calling CancelSync on handler.
                    handler->CancelSync();
                }
                break;
            }
			case LODATA_TEST_SYNC_INTERRUPTED:
                break;
            default:
                break;

        }

        return false;
    }
};
#endif

struct request_queue_context_t {
    __weak StoreWrapper* this_store;
};
