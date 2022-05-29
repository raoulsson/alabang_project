//
//  DMCPSwiftBridge.swift
//  alabang_project
//
//  Created by raoul on 28.5.2022.
//

import Foundation

fileprivate var shared = ""

public class DMCPSwiftBridge {
    
    private var message = "start"
    
    public init() {
        
    }
    
    public func startKeyListenerInLib() {
        print(self.message)
        self.startup()
        self.runMyTimer()
    }
    
    private func startup() {
        // run on a separate queue so we can go on with UI on main thread.
        DispatchQueue.global(qos: .userInitiated).async {
            c_start_client_lib_loop()
            print("done")
        }
    }
    
    
    private func runMyTimer() {
        // use a timee to access buffer.
        // (we CANNOT access member vars... would be nice if we could set directly:
        //   @State private var message
        // rthat is observed.. but globals cannot be observed.

        let _ = Timer.scheduledTimer(withTimeInterval: 1.0, repeats: true) { timer in
            self.message = shared
            print("S: " + self.message)
        }
    }
    
}

@_cdecl("swift_inc_x")
func swift_inc_x(x: Int) -> Int {
    // swift process data...
    shared = "B: \(x)"
    return x + 2
}
