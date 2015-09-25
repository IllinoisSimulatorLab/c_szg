#ifndef SZG_CLIENT_H
#define SZG_CLIENT_H

#include "arSZGClient.h"

extern "C" {
    // arSZGClient
    //
    arSZGClient* EXPORT_API szgClient();
    void EXPORT_API szgClient_delete( arSZGClient* cli );

    int EXPORT_API szgClient_connect( arSZGClient* cli, char* forcedName );
    void EXPORT_API szgClient_disconnect( arSZGClient* cli );


//    bool sendInitResponse(bool ok);
//    bool sendStartResponse(bool ok);

//    string getAttribute(const string& computerName, const string& groupName, const string& parameterName, const string& validValues /* no default */);

//    string getAttribute(const string& groupName, const string& parameterName, const string& validValues = "");

//    int getAttributeInt(const string& groupName, const string& parameterName);
//    int getAttributeInt(const string&, const string&, const string&, const string&);

//    bool getAttributeFloats(const string& groupName, const string& parameterName, float* values, int numvalues = 1);
//    bool getAttributeInts(const string& groupName, const string& parameterName, int* values, int numvalues = 1);
//    bool getAttributeLongs(const string& groupName, const string& parameterName, long* values, int numvalues = 1);
//    bool getAttributeVector3( const string& groupName, const string& parameterName, arVector3& value );

//    string getAllAttributes(const string& substring);
//    const string getDataPath();

//    string getGlobalAttribute(const string& attributeName);

//    const string& getLabel() const;
//    const string& getComputerName() const;
//    const string& getUserName() const;
//    string launchinfo(const string&, const string&) const;

//    string getProcessList();
//    bool killProcessID(int id);
//    bool killProcessID(const string& computer, const string& processLabel);
//    void killIDs(list<int>*);
//    string getProcessLabel(int processID);
//    int getProcessID(const string& computer, const string& processLabel);
//    int getProcessID(void); // my own process ID
//    string getDisplayName(const string&);

//    int sendMessage(const string& type, const string& body, int destination,
//                                     bool responseRequested = false);
//    int sendMessage(const string& type, const string& body,
//                                     const string& context, int destination,
//                                     bool responseRequested = false);
//    int receiveMessage(string* messageType, string* messageBody)
//        { return receiveMessage(NULL, messageType, messageBody, NULL); }
//    int receiveMessage(string* userName, string* messageType, string* messageBody)
//        { return receiveMessage(userName, messageType, messageBody, NULL); }
//    int receiveMessage(string* userName, string* messageType,
//                                            string* messageBody, string* context);
//    int getMessageResponse(list<int> tags,
//                                                 string& body,
//                                                 int& match,
//                                                 int timeout = -1);
//    bool messageResponse(int messageID, const string& body,
//                                             bool partialResponse = false);

//    bool getLock(const string& lockName, int& ownerID);
//    bool releaseLock(const string& lockName);
//    vector<string> findLocks();

//    bool registerService(const string& serviceName, const string& channel,
//                                             int numberPorts, int* portIDs);
//    bool requestNewPorts(const string& serviceName, const string& channel,
//                                             int numberPorts, int* portIDs);
//    bool confirmPorts(const string& serviceName, const string& channel,
//                                        int numberPorts, int* portIDs);
//    arPhleetAddress discoverService(const string& serviceName,
//                                                                    const string& networks,
//                                                                    const bool async);
//    string getServiceInfo(const string& serviceName);
//    vector<string> findServices(const string& type);
//    vector<string> findActiveServices();
//    vector<string> findPendingServices();
//    int    getServiceComponentID(const string& serviceName);

//    arSlashString getNetworks(const string& channel);
//    arSlashString getAddresses(const string& channel);
//    const string& getVirtualComputer();
//    string getVirtualComputers();
//    const string& getMode(const string& channel);
//    void setMode( const string& channel, const string& value );
//    string getTrigger(const string& virtualComputer);

//    string createComplexServiceName(const string& serviceName);
//    string createContext();
//    string createContext(const string& virtualComputer,
//                                             const string& modeChannel,
//                                             const string& mode,
//                                             const string& networksChannel,
//                                             const arSlashString& networks);

//    bool discoverSZGServer(const string& name,
//                                                 const string& broadcast);
//    vector<string> findSZGServers(const string& broadcast);
//    void setServerLocation(const string& IPaddress, int port);

//    bool sendReload(const string& computer, const string& processLabel);

//    bool connected() const;
//    const string& getServerName();
//    void messageTask();
//    void messageTaskStop();
//    bool running() const;
    
}

#endif

