//
//  DNPopupBarAppearance+Private.h
//  DNPopupController
//
//  Created by Léo Natan on 2021-06-20.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import "DNPopupBarAppearance.h"

NS_ASSUME_NONNULL_BEGIN

@interface _DNPopupDominantColorTrait : NSObject <UIObjectTraitDefinition> @end

@protocol _DNPopupBarAppearanceDelegate <NSObject>

- (void)popupBarAppearanceDidChange:(DNPopupBarAppearance*)popupBarAppearance;

@end

@interface DNPopupBarAppearance ()

@property (nonatomic, weak) id<_DNPopupBarAppearanceDelegate> delegate;

- (UIBlurEffect *)floatingBackgroundEffectForTraitCollection:(UITraitCollection*)traitCollection;

@end

NS_ASSUME_NONNULL_END
