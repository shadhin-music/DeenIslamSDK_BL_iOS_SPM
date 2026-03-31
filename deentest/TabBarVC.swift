//
//  TabBarVC.swift
//  DeenIslamExample
//
//  Created by Joy on 20/8/23.
//

import UIKit
import DeenIslamSDK


class TabBarVC: UITabBarController {
    
    var token : String?
    
    init(){
        super.init(nibName: "TabBarVC", bundle: nil)
    }
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.isNavigationBarHidden = true
        
        // Tab A
        let aItem = UITabBarItem(title: "Home", image: UIImage(named: "home"), tag: 0)
        let a = HomeVC()
        a.token = token
        let aNav = UINavigationController(rootViewController: a)
        aNav.tabBarItem = aItem
        
        // Tab B
//        let bItem = UITabBarItem(title: "B", image: UIImage(named: "home"), tag: 1)
//        let b = A()
//        b.token = token
//        let bNav = UINavigationController(rootViewController: b)
//        bNav.tabBarItem = bItem

        // Pass navigation controller to `A`
//        if let bVC = b as? A {
//            bVC.navigationController = bNav
//        }
//        
        // Tab C
        let cItem = UITabBarItem(title: "C", image: UIImage(named: "home"), tag: 2)
        let c = C()
        c.token = token
        let cNav = UINavigationController(rootViewController: c)
        cNav.tabBarItem = cItem
        
        viewControllers = [cNav, /*bNav,*/ aNav]
    }


    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
    }
    

}
