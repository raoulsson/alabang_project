//
//  Level.m
//  alabang_project
//
//  Created by raoul on 27.5.2022.
//

#import "Level.h"
#import <alabang_project/alabang_project-Swift.h>

@interface Level ()

@property (nonatomic, strong) NSMutableArray<GameCharacter *> *gameCharaters;

@end

@implementation Level

- (instancetype)init {
    if(self = [super init]) {
        self.gameCharaters = [NSMutableArray new];
        NSLog(@"The Level is initialized");
    }
    return self;
}

- (void)addCharacter:(GameCharacter *)gameCharacter {
    [self.gameCharaters addObject:gameCharacter];
}

- (NSMutableArray<GameCharacter *> *)allGameCharacters {
    return self.gameCharaters;
}

- (GameCharacter *)getOneCharacter {
    return _gameCharaters[0];
}

@end
