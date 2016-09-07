//
//  AppDelegate.m
//  CustomPatchViewer
//
//  Created by Max Weisel on 11/19/15.
//  Copyright © 2015 Max Weisel. All rights reserved.
//

#import "AppDelegate.h"
#import <Performer/PMDocumentConnectionManager.h>
#import <Performer/PMDocumentCacheManager.h>
#import <Performer/PMDocumentPresentationCoordinator.h>
#import "ConnectViewController.h"

@interface AppDelegate ()

@property (strong, nonatomic) PMDocumentConnectionManager *connectionManager;
@property (strong, nonatomic) PMDocumentCacheManager *documentManager;
@property (strong, nonatomic) PMDocumentPresentationCoordinator *presentationCoordinator;

@end

@implementation AppDelegate

- (void)openDocumentAtURL:(NSURL *)url {
    NSError *error = nil;
    PMRDocumentViewController *vc = [[PMRDocumentViewController alloc] initWithURL:url error:&error];
    if (vc == nil) {
        NSLog(@"Failed to create document view controller: %@", error);
        return;
    }
    
    vc.delegate = (id<PMRDocumentViewControllerDelegate>)_connectionManager;
    vc.options = PMRDocumentOptionsNone;
    
    // if the current presented doc is server connected, we need to disconnect so the host knows
    if ([_presentationCoordinator.documentViewController isConnectedWithHost]) {
        [_connectionManager restartServer];
    }
    
    [_presentationCoordinator openDocumentWithViewController:vc animate:YES handler:nil];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

    // presentation coordinator manages showing form documents
    _presentationCoordinator = [[PMDocumentPresentationCoordinator alloc] initWithWindow:self.window];

    _documentManager = [[PMDocumentCacheManager alloc] init];

    // assemble the main UI layout
    self.window.rootViewController = [[ConnectViewController alloc] init];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];

    application.idleTimerDisabled = YES;

    // start the server to handle inbound connections now that the app is ready
    _connectionManager = [[PMDocumentConnectionManager alloc] initWithPresentationCoordinator:_presentationCoordinator
                                                                                 cacheManager:_documentManager];
    [_connectionManager restartServer];
    
    NSString *path = [[NSBundle mainBundle] pathForResource:@"jackbdayapp" ofType:@"form"];
    NSURL *fileURL = [NSURL fileURLWithPath:path];
    [self openDocumentAtURL:fileURL];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Close document and connection cleanly
 //   if (_presentationCoordinator.viewState == PMDocumentViewStatePresenting) {
 //       [_presentationCoordinator closeDocumentWithAnimation:NO handler:nil];
 //   }

   // [_connectionManager shutdownServer];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [_connectionManager restartServer];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
