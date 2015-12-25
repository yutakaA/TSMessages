//
//  TSMessageView.h
//  Felix Krause
//
//  Created by Felix Krause on 24.08.12.
//  Copyright (c) 2012 Felix Krause. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TSMessage.h"

#define TSMessageViewAlpha 0.95




@interface TSMessageView : UIView

/** The displayed title of this message */
@property (nonatomic, readonly) NSString *title;

/** The displayed subtitle of this message */
@property (nonatomic, readonly) NSString *subtitle;

/** The view controller this message is displayed in */
@property (nonatomic, readonly) UIViewController *viewController;

/** The duration of the displayed message. If it is 0.0, it will automatically be calculated */
@property (nonatomic, assign) CGFloat duration;

// NOTE: アニメーションの速度もカスタマイズできるように追加
@property (nonatomic, assign) CGFloat animationDuration;

/** The position of the message (top or bottom) */
@property (nonatomic, assign) TSMessageNotificationPosition messagePosition;

/** Is the message currenlty fully displayed? Is set as soon as the message is really fully visible */
@property (nonatomic, assign) BOOL messageIsFullyDisplayed;

/** Customize title font using Apperance */
@property (nonatomic,strong) UIFont *titleFont UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIColor *titleTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIFont *contentFont UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIColor *contentTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIImage *messageIcon UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIImage *errorIcon UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIImage *successIcon UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIImage *warningIcon UI_APPEARANCE_SELECTOR;

// NOTE: labelの位置などカスタマイズできるようにhファイルに移動
/** Internal properties needed to resize the view on device rotation properly */
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *contentLabel;
@property (nonatomic, strong) UIImageView *iconImageView;
@property (nonatomic, strong) UIButton *button;
@property (nonatomic, strong) UIView *borderView;
@property (nonatomic, strong) UIImageView *backgroundImageView;
@property (nonatomic, strong) TSBlurView *backgroundBlurView; // Only used in iOS 7
@property (nonatomic, assign) CGFloat textSpaceLeft;
@property (nonatomic, assign) CGFloat textSpaceRight;
@property (copy) void (^callback)();
@property (copy) void (^buttonCallback)();

/** Inits the notification view. Do not call this from outside this library.
 @param title The title of the notification view
 @param subtitle The subtitle of the notification view (optional)
 @param image A custom icon image (optional)
 @param notificationType The type (color) of the notification view
 @param duration The duration this notification should be displayed (optional)
 @param viewController The view controller this message should be displayed in
 @param callback The block that should be executed, when the user tapped on the message
 @param buttonTitle The title for button (optional)
 @param buttonCallback The block that should be executed, when the user tapped on the button
 @param position The position of the message on the screen
 @param dismissingEnabled Should this message be dismissed when the user taps/swipes it?
 */
- (id)initWithTitle:(NSString *)title
           subtitle:(NSString *)subtitle
              image:(UIImage *)image
               type:(TSMessageNotificationType)notificationType
           duration:(CGFloat)duration
  animationDuration:(CGFloat)animationDuration
   inViewController:(UIViewController *)viewController
           callback:(void (^)())callback
        buttonTitle:(NSString *)buttonTitle
     buttonCallback:(void (^)())buttonCallback
         atPosition:(TSMessageNotificationPosition)position
canBeDismissedByUser:(BOOL)dismissingEnabled;

// NOTE: メッセージのみのViewにしたい時のinitを追加
- (id)initWithMessage:(NSString *)message
                 type:(TSMessageNotificationType)notificationType
             duration:(CGFloat)duration
    animationDuration:(CGFloat)animationDuration
     inViewController:(UIViewController *)viewController
             callback:(void (^)())callback
       buttonCallback:(void (^)())buttonCallback
           atPosition:(TSMessageNotificationPosition)position
 canBeDismissedByUser:(BOOL)dismissingEnabled;


/** Fades out this notification view */
- (void)fadeMeOut;

/** Use this method to load a custom design file */
+ (void)addNotificationDesignFromFile:(NSString *)file;

// NOTE: labelの配置などを決める
// Swiftから使用する際→extensionでオリジナルにカスタマイズしてね
- (CGFloat)updateHeightOfMessageView;
- (void)layoutSubviews;

@end
