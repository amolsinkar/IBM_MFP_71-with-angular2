/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLWifiAccessPointFilter_H_
#import <Foundation/Foundation.h>
@class WLWifiAccessPoint;

/**
 * Specifies which WiFi access points to detect.
 * 
 * The filter has an SSID name specification, and optionally a MAC specification.
 * The MAC specification can be a wildcard value, represented by WILDCARD, which is an asterisk (*), 
 * in which case all MACs for the SSID are reported.
 * 
 * If no MAC is specified, and the given SSID is visible, then only its SSID is reported;
 * only a single WLWifiAccessPoint instance will result from acquisition, regardless of the number of access points that have the SSID.
 * 
 * The SSID specification can be a wildcard, represented by WILDCARD, which is an asterisk (*), in which case all visible networks are reported.
 */
@interface WLWifiAccessPointFilter : NSObject {
	@private
	NSString* ssid;
	NSString* mac;
}



+ (void) initialize  ;

/**
	 * Creates a new filter that accepts any MAC address
	 * 
	 * @param ssid The SSID specification. Cannot be null.
	 */
- (id) init : (NSString*) ssid ;
/**
	 * Creates a new filter
	 * 
	 * @param ssid The SSID specification. Cannot be null.
	 * @param mac The MAC specification
	 */
- (id)initWithSSID:(NSString*)ssid MAC:(NSString*)mac;

//TO DO : was containing an unsupported @exclude tag
/**
	 * @param point The access point to check
	 * @return <code>true</code> iff the point's SSID and MAC match the filter's SSID and MAC
	 */
- (BOOL) matches : (WLWifiAccessPoint*) point ;

// TO DO: was containing an unsupported @exclude tag
/**
	 * Returns true if there is a WLWifiLocation that can be matched by both filters
	 * 
	 * @param filter The filter
	 * @return <code>true</code> There could exists a WLWifiAccessPoint that could be matched by both filters
	 */
- (BOOL) isIntersectionNotEmpty : (WLWifiAccessPointFilter*) filter ;
/**
	 * @return The MAC specification
	 */
- (NSString*) getMac  ;
/**
	 * @return The SSID specification
	 */
- (NSString*) getSsid  ;
- (NSString*) description  ;
- (int) hash  ;
- (BOOL) isEqual : (NSObject*) obj ;

@end

extern NSString* WILDCARD;


