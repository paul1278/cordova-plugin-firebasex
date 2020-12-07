#import <Cordova/CDV.h>
#import "AppDelegate.h"
#import "Firebase.h"

@interface FirebasePlugin : CDVPlugin

- (void)setAutoInitEnabled:(CDVInvokedUrlCommand*)command;
- (void)isAutoInitEnabled:(CDVInvokedUrlCommand*)command;

// Remote notifications
- (void)getId:(CDVInvokedUrlCommand*)command;
- (void)getToken:(CDVInvokedUrlCommand*)command;
- (void)getAPNSToken:(CDVInvokedUrlCommand*)command;
- (NSString *)hexadecimalStringFromData:(NSData *)data;
- (void)grantPermission:(CDVInvokedUrlCommand*)command;
- (void)hasPermission:(CDVInvokedUrlCommand*)command;
- (void)setBadgeNumber:(CDVInvokedUrlCommand*)command;
- (void)getBadgeNumber:(CDVInvokedUrlCommand*)command;
- (void)subscribe:(CDVInvokedUrlCommand*)command;
- (void)unsubscribe:(CDVInvokedUrlCommand*)command;
- (void)unregister:(CDVInvokedUrlCommand*)command;
- (void)onMessageReceived:(CDVInvokedUrlCommand*)command;
- (void)onTokenRefresh:(CDVInvokedUrlCommand*)command;
- (void)onApnsTokenReceived:(CDVInvokedUrlCommand *)command;
- (void)sendNotification:(NSDictionary*)userInfo;
- (void)sendToken:(NSString*)token;
- (void)sendApnsToken:(NSString*)token;
- (void)clearAllNotifications:(CDVInvokedUrlCommand *)command;

// Internals
+ (FirebasePlugin *) firebasePlugin;
- (void) handlePluginExceptionWithContext: (NSException*) exception :(CDVInvokedUrlCommand*)command;
- (void) handlePluginExceptionWithoutContext: (NSException*) exception;
- (void) _logError: (NSString*)msg;
- (void) _logInfo: (NSString*)msg;
- (void) _logMessage: (NSString*)msg;
- (void)executeGlobalJavascript: (NSString*)jsString;

- (void)createChannel:(CDVInvokedUrlCommand *)command;
- (void)setDefaultChannel:(CDVInvokedUrlCommand *)command;
- (void)deleteChannel:(CDVInvokedUrlCommand *)command;
- (void)listChannels:(CDVInvokedUrlCommand *)command;

@property (nonatomic, copy) NSString *notificationCallbackId;
@property (nonatomic, copy) NSString *tokenRefreshCallbackId;
@property (nonatomic, copy) NSString *apnsTokenRefreshCallbackId;
@property (nonatomic, copy) NSString *googleSignInCallbackId;
@property (nonatomic, copy) NSString *appleSignInCallbackId;

@property (nonatomic, retain) NSMutableArray *notificationStack;
@property (nonatomic, readwrite) NSMutableDictionary* traces;

@end
