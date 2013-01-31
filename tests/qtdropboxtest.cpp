#include "qtdropboxtest.hpp"

QtDropboxTest::QtDropboxTest()
{
}


/*!
 * \brief QDropboxJson: Simple string read
 * JSON represents an object with single string value. The test
 * tries to read the string value.
 */
void QtDropboxTest::testCase1()
{
    QDropboxJson json("{\"string\":\"asdf\"}");
    QVERIFY2(json.isValid(), "json validity");
    QVERIFY2(json.getString("string").compare("asdf") == 0, "string value does not match");
}

/*!
 * \brief QDropboxJson: Simple int read
 * JSON represents an object with a single integer value. The test
 * tries to read that value.
 */
void QtDropboxTest::testCase2()
{
    QDropboxJson json("{\"int\":1234}");
    QVERIFY2(json.isValid(), "json validity");
    QVERIFY2(json.getInt("int") == 1234, "integer value does not match");
}

/*!
 * \brief QDropboxJson: Injson validity check
 * JSON is invalid. Test confirms invalidity of the JSON.
 */
void QtDropboxTest::testCase3()
{
    QDropboxJson json("{\"test\":\"foo\"");
    QVERIFY2(!json.isValid(), "injson validity not confirmed");
}

/*!
 * \brief QDropboxJson: Simple boolean read
 * JSON contains a single boolean value. Test accesses this value.
 */
void QtDropboxTest::testCase4()
{
    QDropboxJson json("{\"bool\":true}");
    QVERIFY2(json.isValid(), "json validity");
    QVERIFY2(json.getBool("bool"), "boolean value does not match");
}

/*!
 * \brief QDropboxJson: Simple floating point read
 * JSON contains a single double value. Test reads it.
 */
void QtDropboxTest::testCase5()
{
    QDropboxJson json("{\"double\":14.323667}");
    QVERIFY2(json.isValid(), "json validity");
    QVERIFY2(json.getDouble("double"), "double value does not match");
}

/*!
 * \brief QDropboxJson: Subjson read
 * JSON contains a subjson that is read, but not evaluated.
 */
void QtDropboxTest::testCase6()
{
    QDropboxJson json("{\"json\": {\"string\":\"abcd\"}}");
    QVERIFY2(json.isValid(), "json validity");

    QDropboxJson* subjson = json.getJson("json");

    QVERIFY2(subjson!=NULL, "subjson is null");
    QVERIFY2(subjson->isValid(), "subjson invalid");
}

/*!
 * \brief QDropboxJson: Simple unsigned integer read.
 * JSON contains single unsigned integer that is read.
 */
void QtDropboxTest::testCase7()
{
    QDropboxJson json("{\"uint\":4294967295}");
    QVERIFY2(json.isValid(), "json validity");
    QVERIFY2(json.getUInt("uint") == 4294967295, "unsigned int value does not match");
}

/**
 * @brief QDropboxJson: Test if clear works correctly
 */
void QtDropboxTest::testCase8()
{
    QDropboxJson json("{\"uint\":4294967295}");
    QVERIFY2(json.isValid(), "json validity");
    json.clear();
    QVERIFY2(json.getUInt("uint") == 0, "internal list not cleared");
    QVERIFY2(json.strContent().isEmpty(), "json string is not cleared");
}

QTEST_MAIN(QtDropboxTest)