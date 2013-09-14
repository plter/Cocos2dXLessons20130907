//
//  CustomCell.m
//  L003UsingUITableView
//
//  Created by plter on 13-9-14.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#import "CustomCell.h"

@implementation CustomCell

@synthesize label;

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
        
        self.label = [[UILabel alloc] init];
        self.label.text = @"Label";
        
        [self addSubview:label];
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
