//
//  L003UsingTableViewInCocos2dXAppController.h
//  L003UsingTableViewInCocos2dX
//
//  Created by plter on 13-9-14.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;

@end

