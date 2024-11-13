#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>  // ��� strncmp �� strcat_s
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    // �������, ��� �� �������
    char* ReplacePatternWithAsterisks(const char* s, bool& foundPattern) {
        foundPattern = false;
        char* result = new char[201];
        result[0] = '\0';
        int t_size = 200;
        int j = 0;
        const char* current = s;

        while (*current != '\0') {
            if ((strncmp(current, "OGO", 3) == 0) || (strncmp(current, "AGA", 3) == 0)) {
                if (j + 2 < t_size) {
                    strcat_s(result, t_size, "**"); // ������������� strcat_s
                    j += 2;
                    foundPattern = true;
                }
                current += 3;
            }
            else {
                if (j < t_size - 1) {
                    result[j] = *current;
                    result[j + 1] = '\0';
                    j++;
                }
                current++;
            }
        }

        return result;
    }

    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestPatternReplaced) {
            // Arrange
            const char* input = "The OGO and AGA are here.";
            bool foundPattern = false;
            const char* expected = "The ** and ** are here.";

            // Act
            char* result = ReplacePatternWithAsterisks(input, foundPattern);

            // Assert
            Assert::AreEqual(true, foundPattern);  // ����������, �� �������� ������
            Assert::AreEqual(expected, result);  // ����������, �� ��������� ����������

            delete[] result; // ������� ���'��
        }

        TEST_METHOD(TestPatternNotFound) {
            // Arrange
            const char* input = "This string has no patterns.";
            bool foundPattern = false;
            const char* expected = "This string has no patterns.";

            // Act
            char* result = ReplacePatternWithAsterisks(input, foundPattern);

            // Assert
            Assert::AreEqual(false, foundPattern);  // ����������, �� �� �������� ������
            Assert::AreEqual(expected, result);  // ����������, �� ��������� ����������

            delete[] result; // ������� ���'��
        }

        TEST_METHOD(TestEmptyString) {
            // Arrange
            const char* input = "";
            bool foundPattern = false;
            const char* expected = "";

            // Act
            char* result = ReplacePatternWithAsterisks(input, foundPattern);

            // Assert
            Assert::AreEqual(false, foundPattern);  // ����������, �� �� �������� ������
            Assert::AreEqual(expected, result);  // ����������, �� ��������� ����������

            delete[] result; // ������� ���'��
        }
    };
}
