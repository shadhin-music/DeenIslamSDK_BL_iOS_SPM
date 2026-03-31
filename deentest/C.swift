//
//  C.swift
//  Shadhin-BL-Example
//
//  Created by Joy on 1/12/22.
//

import UIKit
import DeenIslamSDK

class C: UIViewController {
//    @IBOutlet weak var cView: CustomView!
    @IBOutlet weak var gotoDeen: UIButton!
    
    init(){
        super.init(nibName: "C", bundle: nil)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    var token : String?
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
    
        
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        gotoDeen.addTarget(self,
                              action: #selector(gotoDenAction),
                              for: .touchUpInside)
        }

        @objc private func gotoDenAction() {
            DeenIslamBLSDK.shared.gotoHome(tabBar: self.tabBarController, nav: self.navigationController!)
        }

    


}


extension C : DeenIslamSDKNotifier{
    func deenPaymentEvent(eventName: String, parameters: [String : String]) {
        print("Payment name: \(eventName)")
        print("Event parameters:")
           for (key, value) in parameters {
               print("\(key): \(value)")
           }
    }
    
    func errorMessage(error: String) {
        
    }
    
    func tokenStatus(token isValid: Bool, error: String?) {
        if isValid{
            print("token is valid")
        }else{
            print(error ?? "error")
        }
    }
}
