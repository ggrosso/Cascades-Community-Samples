/* Copyright (c) 2014 BlackBerry Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * The Lithium REST APIs are owned by Lithium Technologies, Inc.
 * (http://www.lithium.com) and are not part of the “Works” licensed
 * hereunder pursuant to the Apache 2.0 license.
 */

#ifndef CATEGORYPROVIDER_HPP_
#define CATEGORYPROVIDER_HPP_

#include "ForumRequest.hpp"
#include "URLProvider.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>
#include <bb/cascades/ArrayDataModel>
#include <bb/data/XmlDataAccess>


class CategoryProvider : public QObject
{
Q_OBJECT

Q_PROPERTY(bb::cascades::DataModel* model READ model NOTIFY categoryRequestReady)

public:

	CategoryProvider(QObject *parent = 0);

Q_SIGNALS:

	/*
	 * This signal is emitted the category list is ready.
	 */
	void categoryRequestReady();

	/*
	 * This signal is emitted when the category request fails.
	 * @param error - The error message returned.
	 */
	void categoryRequestFailed(QString error);

public Q_SLOTS:

	/*
	 * This slot is to initiate the request to download categories.
	 * @param categoryId - The uber category Id to list categories for.
	 */
	void makeCategoryRequest(QString categoryId);

	/*
	 * This slot is to receive the signal emitted when the forum network request is complete
	 * @param info - on success, this is the xml reply from the request
	 *               on failure, it is an error string
	 * @param success - true if request succeed, false if not
	 */
	void requestComplete(const QString &info, bool success);

private:

	bb::cascades::DataModel* model() const;

	bb::cascades::ArrayDataModel* mCategoryData;
	ForumRequest* mForumRequest;

};

#endif /* CATEGORYPROVIDER_HPP_ */
