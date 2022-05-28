//
//  Level.h
//  alabang_project
//
//  Created by raoul on 27.5.2022.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class GameCharacter;

@interface Level : NSObject

- (NSMutableArray<GameCharacter *> *)allGameCharacters;
- (void)addCharacter:(GameCharacter *)gameCharacter;
- (GameCharacter *)getOneCharacter;

@end

NS_ASSUME_NONNULL_END
