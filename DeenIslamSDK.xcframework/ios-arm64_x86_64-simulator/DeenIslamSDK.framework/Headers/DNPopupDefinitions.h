//
//  DNPopupDefinitions.h
//  DNPopupController
//
//  Created by Léo Natan on 2021-12-16.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#ifndef DNPopupDefinitions_h
#define DNPopupDefinitions_h

#import <Foundation/Foundation.h>

#ifndef NS_SWIFT_UI_ACTOR
#define NS_SWIFT_UI_ACTOR
#endif

#ifndef NS_SWIFT_DISABLE_ASYNC
#define NS_SWIFT_DISABLE_ASYNC
#endif

#define DN_UNAVAILABLE_API(x) __attribute__((unavailable(x)))
#define DN_DEPRECATED_API(x) __attribute__((deprecated(x)))

#endif /* DNPopupDefinitions_h */
