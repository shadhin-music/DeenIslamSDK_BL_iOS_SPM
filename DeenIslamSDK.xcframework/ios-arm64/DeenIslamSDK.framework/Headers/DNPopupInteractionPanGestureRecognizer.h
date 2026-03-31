//
//  DNPopupInteractionPanGestureRecognizer.h
//  DNPopupController
//
//  Created by Léo Natan on 2017-07-15.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DNPopupController;

@interface DNPopupInteractionPanGestureRecognizer : UIPanGestureRecognizer

- (instancetype)initWithTarget:(id)target action:(SEL)action popupController:(DNPopupController*)popupController;

@end
