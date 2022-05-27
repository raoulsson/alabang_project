//
//  ContentView.swift
//  GameLibClient
//
//  Created by raoul on 27.5.2022.
//

import SwiftUI
import alabang_project

struct ContentView: View {
    let gameCharacter = GameCharacter(name: "AlaBangNam")
    
    var body: some View {
        Text("Hello, world...! " + gameCharacter.name)
            .padding()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
