//
//  MMShadowHand.h
//  LooseLeaf
//
//  Created by Adam Wulf on 1/19/15.
//  Copyright (c) 2015 Milestone Made, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

@interface MMShadowHand : NSObject

// the layer that contains the hand shadow
@property (readonly) CALayer* layer;
// the id of the object that's being held with a pan, nil otherwise
@property (strong) id heldObject;
// YES if the hand is actively being shown, NO otherwise
-(BOOL) isActive;
-(BOOL) isDrawing;

// @param isRight: YES if this should show only the right hand, NO for the left hand
// @param relativeView: the view that should track touch locations
-(id) initForRightHand:(BOOL)isRight forView:(UIView*)relativeView;

// bezel
-(void) startBezelingInFromRight:(BOOL)fromRight withTouches:(NSArray*)touches;
-(void) continueBezelingInFromRight:(BOOL)fromRight withTouches:(NSArray*)touches;
-(void) endBezelingInFromRight:(BOOL)fromRight withTouches:(NSArray*)touches;

// pinching a page
-(void) startPinchingObject:(id)obj withTouches:(NSArray*)touches;
-(void) continuePinchingObject:(id)obj withTouches:(NSArray*)touches;
-(void) endPinchingObject:(id)obj;

// panning a page
-(void) startPanningObject:(id)obj withTouches:(NSArray*)touches;
-(void) continuePanningObject:(id)obj withTouches:(NSArray*)touches;
-(void) endPanningObject:(id)obj;

// drawing
-(void) startDrawingAtTouch:(CGPoint)touch;
-(void) continueDrawingAtTouch:(CGPoint)touch;
-(void) endDrawing;

@end
