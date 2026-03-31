//
//  DNPopupCloseButton+Private.h
//  DNPopupController
//
//  Created by Léo Natan on 2016-12-02.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import "DNPopupCloseButton.h"
#import "DNPopupContentView.h"

@interface DNPopupCloseButton ()

- (instancetype)initWithContainingContentView:(DNPopupContentView*)contentView;

@property (nonatomic, weak) DNPopupContentView* popupContentView;

- (void)_setStyle:(DNPopupCloseButtonStyle)style;
- (void)_setButtonContainerStationary;
- (void)_setButtonContainerTransitioning;

@end
