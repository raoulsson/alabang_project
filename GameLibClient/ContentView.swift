//
//  ContentView.swift
//  GameLibClient
//
//  Created by raoul on 27.5.2022.
//

import SwiftUI
import alabang_project

class SomeClass {
    
    let level = Level()
    
    func generateSomeData() -> SomeClass {
        let gameCharacter = GameCharacter(name: "AlaBangNam")
        
        level.add(gameCharacter)
        level.add(GameCharacter(name: "Jingo"))
        
        let characters = level.allGameCharacters()
    
        for character in characters {
            print((character as! GameCharacter).say(text: "xyz"))
        }

        return self
    }
    
    func getOneName() -> String {
        return level.getOneCharacter().name
    }
    
}

struct ContentView: View {
    
    let someClass = SomeClass()
    
    init() {
        let bridge = DMCPSwiftBridge()
        bridge.startKeyListenerInLib()
    }
    
    var body: some View {
        Text("Hello, world...! " + someClass.generateSomeData().getOneName())
            .padding()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
