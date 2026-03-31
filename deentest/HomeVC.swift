//
//  HomeVC.swift
//  Shadhin-BL-Example
//
//  Created by Joy on 29/11/22.
//

import UIKit
import DeenIslamSDK
import SwiftUI

class HomeVC: UIViewController {
    
    init(){
        super.init(nibName: "HomeVC", bundle: nil)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    @IBOutlet weak var tableView: UITableView!
    
    @IBOutlet weak var bottomConstraint: NSLayoutConstraint!
    @IBOutlet weak var textField: UITextField!
    
    @IBOutlet weak var sessionTimeButton: UIButton!
    
    @IBOutlet weak var sessionTimeTV: UITextField!
    
    private var dataSource : [String] = ["Home","Islamic Name","Tasbeeh","Daily Dua","Hadith","PrayerTime","Qibla", "Zakat","Al Quran","", "IslamicEvent", "NearestMosque", "EidJamatPlace", "NamazLearning", "MoccaModinaLive", "DuaAndAmol", "IslamicLearningStory", "Ramadan", "khotom Quran", "Hajj and Umrah", "Allah All Names", "Islamic Calender","RamadanRR" ,"Quiz"]
    var token : String?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
        tableView.dataSource = self
        tableView.delegate = self
        
        let toolbar = UIToolbar()
        toolbar.frame = CGRect(x: 0, y: 0, width: UIScreen.main.bounds.width, height: 44)
        let done = UIBarButtonItem(title: "Done", style: .done, target: self, action: #selector(onKeyboardDone))
        toolbar.setItems([done], animated: true)
        textField.delegate = self
        textField.inputAccessoryView = toolbar
        
        NotificationCenter.default.addObserver(
            self,
            selector: #selector(keyboardWillShow),
            name: UIResponder.keyboardWillShowNotification,
            object: nil
        )
        NotificationCenter.default.addObserver(
            self,
            selector: #selector(keyboardWillHide),
            name: UIResponder.keyboardWillHideNotification,
            object: nil
        )
        
    }
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        sessionTimeButton.isEnabled = true
        
        
        // Check if SDK is initialized
        if DeenIslamBLSDK.shared.isInitialized {
            // SDK is already initialized
        } else {
            // Need to initialize SDK
            DeenIslamBLSDK.shared.initialize(with: self.tabBarController, nav: self.navigationController!, delegate: self, token: token ?? "", isBL: true)
        }

        
      
    }
    @objc func onKeyboardDone(){
        textField.resignFirstResponder()
    }
    @objc func keyboardWillShow(_ notification: Notification) {
        if let keyboardFrame: NSValue = notification.userInfo?[UIResponder.keyboardFrameEndUserInfoKey] as? NSValue {
            let keyboardRectangle = keyboardFrame.cgRectValue
            let keyboardHeight = keyboardRectangle.height
            UIView.animate(withDuration: 0.2) {
                self.bottomConstraint.constant = keyboardHeight
            }
        }
    }
    @objc func keyboardWillHide(_ notification: Notification) {
        UIView.animate(withDuration: 0.2) {
            
            self.bottomConstraint.constant = 16
        }
    }

   
    @IBAction func onButtonPressed(_ sender: Any) {
        let code = (textField.text ?? "")
                .trimmingCharacters(in: .whitespacesAndNewlines)


        DeenIslamBLSDK.shared.openFromRC(code: code, tabBar : self.tabBarController, nav : self.navigationController!)
    }
    
    @IBAction func onSessionTimeSetPressed(_ sender: Any) {
        DeenIslamBLSDK.shared.logout()
        
    }
}

extension HomeVC : UITableViewDataSource,UITableViewDelegate{
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        if #available(iOS 14.0, *) {
            var content = cell.defaultContentConfiguration()
            content.text = dataSource[indexPath.row]
            cell.contentConfiguration = content
        } else {
            // Fallback on earlier versions
            cell.textLabel?.text = dataSource[indexPath.row]
        }
        
        return cell
    }
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 50
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        //let type =  FeatureType(rawValue: indexPath.row)!
        switch indexPath.row{
        case 0:
            DeenIslamBLSDK.shared.gotoHome(tabBar: self.tabBarController, nav: self.navigationController!)
        case 1:
            DeenIslamBLSDK.shared.goto(feature: .islamic_name, tabBar: self.tabBarController, nav: self.navigationController!)
        case 2:
            DeenIslamBLSDK.shared.goto(feature: .tasbeeh, tabBar: self.tabBarController, nav: self.navigationController!)
        case 3:
            DeenIslamBLSDK.shared.goto(feature: .dua, tabBar: self.tabBarController, nav: self.navigationController!)
        case 4:
            DeenIslamBLSDK.shared.goto(feature: .hadith, tabBar: self.tabBarController, nav: self.navigationController!)
        case 5:
            DeenIslamBLSDK.shared.goto(feature: .prayer_time, tabBar: self.tabBarController, nav: self.navigationController!)
        case 6:
            DeenIslamBLSDK.shared.goto(feature: .compass, tabBar: self.tabBarController, nav: self.navigationController!)
        case 7:
            DeenIslamBLSDK.shared.goto(feature: .zakat, tabBar: self.tabBarController, nav: self.navigationController!)
        case 8:
            DeenIslamBLSDK.shared.goto(feature: .quran, tabBar: self.tabBarController, nav: self.navigationController!)
        case 9: break
            //DeenIslamGPSDK.shared.goto(feature: .ramadan )
        case 10:
            DeenIslamBLSDK.shared.goto(feature: .islamic_event , tabBar: self.tabBarController, nav: self.navigationController!)
        case 11:
            DeenIslamBLSDK.shared.goto(feature: .nearest_mosque, tabBar: self.tabBarController, nav: self.navigationController!)
        case 12:
            DeenIslamBLSDK.shared.goto(feature: .eid_jamat, tabBar: self.tabBarController, nav: self.navigationController!)
        case 13:
            DeenIslamBLSDK.shared.goto(feature: .prayer_learning, tabBar: self.tabBarController, nav: self.navigationController!)
        case 14:
            DeenIslamBLSDK.shared.goto(feature: .live_makkah_madina, tabBar: self.tabBarController, nav: self.navigationController!)
        case 15:
            DeenIslamBLSDK.shared.goto(feature: .duaAndAmol, tabBar: self.tabBarController, nav: self.navigationController!)
        case 16:
            DeenIslamBLSDK.shared.goto(feature: .islamic_golpo, tabBar: self.tabBarController, nav: self.navigationController!)
        case 17:
            DeenIslamBLSDK.shared.goto(feature: .ramadan, tabBar: self.tabBarController, nav: self.navigationController!)
        case 18:
            DeenIslamBLSDK.shared.goto(feature: .khatam_e_quran, tabBar: self.tabBarController, nav: self.navigationController!)
        case 19:
            DeenIslamBLSDK.shared.goto(feature: .hajjandumrah, tabBar: self.tabBarController, nav: self.navigationController!)
        case 20:
            DeenIslamBLSDK.shared.goto(feature: .asmaul_husna, tabBar: self.tabBarController, nav: self.navigationController!)
            
        case 21:
            DeenIslamBLSDK.shared.goto(feature: .islamic_calendar, tabBar: self.tabBarController, nav: self.navigationController!)
        case 22:
            DeenIslamBLSDK.shared.goto(feature: .islamic_boyan, tabBar: self.tabBarController, nav: self.navigationController!)
        case 23:
            DeenIslamBLSDK.shared.goto(feature: .quiz, tabBar: self.tabBarController, nav: self.navigationController!)
            
        default:
            DeenIslamBLSDK.shared.goto(feature: .home, tabBar: self.tabBarController, nav: self.navigationController!)
        }
        
        
    }
}

extension HomeVC : UITextFieldDelegate{
    
}
extension HomeVC : DeenIslamSDKNotifier{
    
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


