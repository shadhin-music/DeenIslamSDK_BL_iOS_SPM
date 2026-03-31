//
//  ViewController.swift
//  DeenIslamExample
//
//  Created by Joy on 20/8/23.
//

import UIKit
import DeenIslamSDK

class ViewController: UIViewController, DeenIslamSDKNotifier {
    func deenPaymentEvent(eventName: String, parameters: [String : String]) {
        print("Payment name: \(eventName)")
        print("Event parameters:")
           for (key, value) in parameters {
               print("\(key): \(value)")
           }
    }
    
    func tokenStatus(token isValid: Bool, error: String?) {
    
    }
    
    func errorMessage(error: String) {
        
    }
    
    
    var token: String?

    @IBOutlet weak var textField: UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        //textField.text = "8801954545813"
       // textField.text = "8801819841259"
        textField.text = "8801672219992"
      //  textField.text = "8801795937303"
        //textField.text = "8801738609138"
        
//        DeenIslamGPSDK.shared.initialize(with: self.tabBarController, nav: self.navigationController!, delegate: self, token: "", isBL: true)
        
    }

    @IBAction func onLoginPressed(_ sender: Any) {
        
        DeenIslamBLSDK.shared.logIn(with: textField.text ?? "" , isBL: true) { token, error in
            if let token = token{
                let tab = TabBarVC()
                self.token = token
                tab.token = token
                self.navigationController?.pushViewController(tab, animated: true
                )
            }else if let error = error{
                debugPrint(error)
            }
            
        }
    }
    
}

