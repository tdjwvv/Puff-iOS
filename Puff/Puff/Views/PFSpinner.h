//
//  PFSpinner.h
//  Puff
//
//  Created by bob.sun on 27/10/2016.
//  Copyright © 2016 bob.sun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MaterialControls/MDTableViewCell.h>
@class PFSpinner;
@protocol PFSpinnerDelegate <NSObject>

@required
- (void)pfSpinner:(PFSpinner* _Nonnull)spinner didSelectItem:(id) item;

@end

typedef  void(^PFSpinnerCellConfigureBlock)(UITableViewCell* cell, NSIndexPath* indexPath, NSObject* dataItem);
typedef void(^PFAnimatedCallback)();

@interface PFSpinner : UIView

@property (weak, nonatomic) id<PFSpinnerDelegate> spinnerDelegate;
@property (strong, nonatomic) PFSpinnerCellConfigureBlock configureCallback;
- (instancetype)initAsSpinnerWithData:(NSArray* _Nonnull)data andFrame:(CGRect)frame;
- (instancetype)initAsMenuWithData:(NSArray* _Nonnull)data andFrame:(CGRect)frame;
- (void)presentInView:(UIView*)view ;
- (void)dismiss:(PFAnimatedCallback)cb;

@end

@interface PFSpinnerCell : MDTableViewCell
@property (strong, nonatomic) UIImageView* iconView;
@property (strong, nonatomic) UILabel* spinnerLabel;
@end

@interface PFSpinnerMenuCell : MDTableViewCell
@property (strong, nonatomic) UILabel *menuLabel;
@end
