//
//  GoogleDocs.h
//  GoogleDocs
//
//  Created by Tom Saxton on 12/19/08.
//  Copyright (c) 2008-2009 Idle Loop Software Design, LLC.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>

@class GDataFeedDocList, GDataServiceTicket, GDataServiceTicket;

@class GoogleDocs;

@protocol GoogleDocsController

- (void)googleDocsAccountVerifyComplete:(BOOL)fSuccess error:(NSError *)error;

- (void)googleDocsUploadProgress:(GoogleDocs *)googledocs read:(unsigned long long)cbRead of:(unsigned long long)cbTotal;
- (void)googleDocsUploadComplete:(GoogleDocs *)googledocs error:(NSError *)error;

- (void)googleDocsDownloadProgress:(GoogleDocs *)googledocs read:(unsigned long long)cbRead ofEstimatedTotal:(unsigned long long)cbTotalEstimate;
- (void)googleDocsDownloadComplete:(GoogleDocs *)googledocs data:(NSData *)data error:(NSError *)error;

- (void)googleDocsRetitleComplete:(BOOL)fSuccess count:(NSInteger)count error:error;

- (void)googleDocsCheckFolder:(BOOL)fExists wasCreated:(BOOL)fCreated error:(NSError *)error;

@end


@interface GoogleDocs : NSObject
{
@private
	NSObject <GoogleDocsController> *m_owner;
	NSString *m_username;
	NSString *m_password;
	
	GDataFeedDocList *m_feedDocList;
	NSError *m_errorDocListFetch;
	GDataServiceTicket *m_ticketDocListFetch;
	GDataServiceTicket *m_ticketUpload;

	// the current Google operation
	NSInteger m_gop;
	NSString *m_title;
	NSArray *m_adirPath;
	NSInteger m_idirPath;
	NSURL *m_urlFolderFeed;
	NSString *m_titleNew;
	NSArray *m_aentryRetitle;
	NSInteger m_ientryRetitle;
	BOOL m_fCanCreateDir;
	BOOL m_fDidCreateDir;
	
	// feed caching
	NSArray *m_adirPathCache;
	NSURL *m_urlFolderFeedCache;
	BOOL m_fUsedCache;

	// upload state
	NSData *m_dataToUpload;
	BOOL m_fReplaceExisting;

	// download state
	long long m_cbDownloadTotalEstimate;
	NSMutableData *m_dataDownload;
}

@property (nonatomic, retain) NSString *username;
@property (nonatomic, retain) NSString *password;

- (id)initWithUsername:(NSString *)username password:(NSString *)password owner:(NSObject <GoogleDocsController> *)owner;

- (void)verifyAccountUsername:(NSString *)username password:(NSString *)password;
- (void)beginUploadData:(NSData *)dataUpload withTitle:(NSString *)title inFolder:(id)dirStringOrArray replaceExisting:(BOOL)fReplaceExisting;
- (void)beginDownloadTitle:(NSString *)title inFolder:(id)dirStringOrArray;
- (void)beginFileRetitleFrom:(NSString *)titleOld toTitle:(NSString *)titleNew inFolder:(id)dirStringOrArray;
- (void)beginFolderCheck:(id)dirStringOrArray createIfNeeded:(BOOL)fCreate;

@end
