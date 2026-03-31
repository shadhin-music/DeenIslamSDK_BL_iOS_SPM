//
//  DNPopupItem+Private.h
//  DNPopupController
//
//  Created by Léo Natan on 2015-08-23.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import "DNPopupItem.h"
#import "DNPopupController.h"

extern NSArray* __DNPopupItemObservedKeys;

@class DNPopupItem;

@protocol _DNPopupItemDelegate <NSObject>

- (void)_popupItem:(DNPopupItem*)popupItem didChangeToValue:(id)value forKey:(NSString*)key;

@end

@interface DNPopupItem ()

@property (nonatomic, strong) UIViewController* swiftuiImageController;

@property (nonatomic, strong) UIView* swiftuiTitleContentView;

@property (nonatomic, strong) UIViewController* swiftuiHiddenLeadingController;
@property (nonatomic, strong) UIViewController* swiftuiHiddenTrailingController;

@property (nonatomic, copy) NSString* accessibilityImageLabel;
@property (nonatomic, copy) NSString* accessibilityProgressLabel;
@property (nonatomic, copy) NSString* accessibilityProgressValue;

@property (nonatomic, weak, setter=_setItemDelegate:, getter=_itemDelegate) id<_DNPopupItemDelegate> itemDelegate;
@property (nonatomic, weak, setter=_setContainerController:, getter=_containerController) __kindof UIViewController* containerController;

@end
