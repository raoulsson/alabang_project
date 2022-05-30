//
//  GameCharacter.swift
//  alabang_project
//
//  Created by raoul on 27.5.2022.
//

import Foundation

// only public can be seen outside of lib
public class GameCharacter {
    
    @objc public let name: String;
    
    public init(name: String) {
        self.name = name
    }
    
    public func say(text: String) {
        let libExample = HelloWorldIOS()
        print("hello " + text + " " + libExample.getHelloWorld())
    }
}
