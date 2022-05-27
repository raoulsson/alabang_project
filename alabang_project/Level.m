//
//  Level.m
//  alabang_project
//
//  Created by raoul on 27.5.2022.
//

#import "Level.h"
#import <alabang_project/alabang_project-Swift.h>

@implementation Level

- (instancetype)init {
    if(self = [super init]) {
        NSLog(@"The Level is initialized");
    }
    return self;
}

- (NSArray<GameCharacter *> *)allGameCharacters {
    return nil;
}

@end
