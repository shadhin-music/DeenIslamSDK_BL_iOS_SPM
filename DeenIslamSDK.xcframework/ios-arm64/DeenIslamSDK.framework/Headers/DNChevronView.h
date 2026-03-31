//
//  DNChevronView.h
//
//  Created by Léo Natan on 2016-12-02.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#define DNChevronView __DNChevronView
#define DNChevronViewState __DNChevronViewState
#define DNChevronViewStateUp __DNChevronViewStateUp
#define DNChevronViewStateFlat __DNChevronViewStateFlat
#define DNChevronViewStateDown __DNChevronViewStateDown

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DNChevronViewState) {
	DNChevronViewStateUp = -1,
	DNChevronViewStateFlat = 0,
	DNChevronViewStateDown = 1
};

@interface DNChevronView : UIView

@property (nonatomic, assign) DNChevronViewState state;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) NSTimeInterval animationDuration;

- (void)setState:(DNChevronViewState)state animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
