//
//  RootView.m
//  GoogleDocs
//
//  Created by Tom Saxton on 2/12/09.
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

#import "RootView.h"


@implementation RootView

@synthesize buttonLogin = m_buttonLogin,
		    buttonUpload = m_buttonUpload,
            buttonDownload = m_buttonDownload,
			buttonRename = m_buttonRename,
			buttonCheckFolder = m_buttonCheckFolder,
			buttonEnsureFolder = m_buttonEnsureFolder,
			spinner = m_spinner,
			labelStatus = m_labelStatus;

- (void)dealloc
{
    [super dealloc];
}

@end
