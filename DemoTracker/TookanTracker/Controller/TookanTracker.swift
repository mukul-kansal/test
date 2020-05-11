//
//  TookanTracker.swift
//  TookanTracker-SDK
//
//  Created by CL-Macmini-110 on 11/21/17.
//  Copyright © 2017 CL-Macmini-110. All rights reserved.
//

import Foundation
import GooglePlaces
import GoogleMaps
import CoreLocation

@objc public protocol TookanTrackerDelegate {
    @objc optional func getCurrentCoordinates(_ location:CLLocation)
    @objc optional func getSessionId(sessionId: String)
    @objc optional func logout()
}

public class TookanTracker: NSObject, CLLocationManagerDelegate {
    public static var shared = TookanTracker()
    private var merchantNavigationController:UINavigationController?
    let loc = LocationTrackerFile.sharedInstance()
    public var delegate:TookanTrackerDelegate!
    let model = TrackerModel()
    var agentDetailModel = AgentDetailModel(json: [:])
    var jobModel = JobModel()
    var jobData = JobData()
    var jobs = Jobs()
    var jobArray = [Jobs]()
    public var getETA = ""
    public var apiKey = ""
    public var delayTimer = 60.0
    public var googleMapKey = ""
    public var jobArrayCount = 0
    var locationManager:CLLocationManager!
    var uiNeeded = false
    var jobID = ""
    var isHideUserDetailOnTop = false
   var completionHandler: ((_ viewC: UIViewController)->())?
    //completionHandler: ((_ mapViewController: UIViewController)->())?
    
    public func createSession(userID:String,isUINeeded:Bool, isHideUserDetailOnTop: Bool = true, completionHandler: ((_ mapViewController: UIViewController)->())?) {
        locationManager = CLLocationManager()
        locationManager.delegate = self
        locationManager.requestAlwaysAuthorization()
        self.uiNeeded = isUINeeded
        globalUserId = userID
       self.completionHandler =  completionHandler

//        globalAPIKey = apiKey
 //       self.merchantNavigationController = navigationController
//        UserDefaults.standard.set(apiKey, forKey: USER_DEFAULT.apiKey)
        UserDefaults.standard.set(userID, forKey: USER_DEFAULT.userId)
        self.isHideUserDetailOnTop = isHideUserDetailOnTop
        self.loc.trackingDelegate = self
    }
    
    public func startTarckingByJob(sharedSecertId: String, jobId: String, userId: String){
    }
    
    public func startTrackingByAgent(sharedSecertId: String, fleetId: String, userId: String){
    
    }
    public func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        
        
        if status == .denied {
            locationManager = CLLocationManager()
            locationManager.requestAlwaysAuthorization()
        } else if status == .authorizedWhenInUse || status == .authorizedAlways {
            
            if let _ = UserDefaults.standard.value(forKey: USER_DEFAULT.sessionId) as? String {
                self.registerForGoogle()
                if uiNeeded {
                    self.initHome()
                } else {
                    self.loc.topic = "\(globalAPIKey)\(globalUserId)"
                    UserDefaults.standard.set(true, forKey: USER_DEFAULT.isLocationTrackingRunning)
                    self.loc.registerAllRequiredInitilazers()
                    UserDefaults.standard.set(true, forKey: USER_DEFAULT.subscribeLocation)
                }
                
            } else {
                if let _ = UserDefaults.standard.value(forKey: USER_DEFAULT.isLocationTrackingRunning) {
                    self.registerForGoogle()
                    if uiNeeded {
                        self.initHome()
                    } else {
                        self.loc.topic = "\(globalAPIKey)\(globalUserId)"
                        UserDefaults.standard.set(true, forKey: USER_DEFAULT.isLocationTrackingRunning)
                        self.loc.registerAllRequiredInitilazers()
                        UserDefaults.standard.set(true, forKey: USER_DEFAULT.subscribeLocation)
                    }
                }
//                else {
//                    self.startSharingLocation()
//                }
            }
        }
    }
    
    @objc func becomeActive() {
        self.loc.trackingDelegate = self
        self.loc.becomeActive()
    }
    
    func initHome() {
        let storyboard = UIStoryboard(name: STORYBOARD_NAME.main, bundle: frameworkBundle)
        if let home  = storyboard.instantiateViewController(withIdentifier: STORYBOARD_ID.home) as? HomeController {
            home.trackingDelegate = self
            home.jobModel = self.jobModel
            home.jobData = self.jobs
            home.getETA = { eta in
                print(eta)
                if eta != "" {
                    self.getETA = eta
                }
            }
            home.isHideTopUserDetailView = isHideUserDetailOnTop
            if let completion = self.completionHandler {
                completion(home)
            }
        //   self.merchantNavigationController?.pushViewController(home, animated: true)
        }
    }
    
    func startSharingLocation() {
        
    }
    
    func registerForGoogle(){
        GMSPlacesClient.provideAPIKey(APIKeyForGoogleMaps)
        GMSServices.provideAPIKey(APIKeyForGoogleMaps)
    }
    
    
    public func stopTracking(sessionID: String) {
    }
}

extension TookanTracker: TrackingDelegate {
    
    public func getCoordinates(_ location: CLLocation) {
        self.delegate.getCurrentCoordinates!(location)
        print("LocationTrackerDelegate inside SDK")
    }
    
    public func logout() {
        self.delegate.logout!()
    }
}
