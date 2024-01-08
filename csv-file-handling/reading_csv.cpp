#include <iostream>
#include <fstream>
#include <string>
// #include <cstring>
using namespace std;

int strlen(string str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void displayFileData(fstream& file) {
    while (!file.eof()) {
        string line = "";
        getline(file, line);
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                line[i] = ' ';
            }
        }
        cout << endl << line;
    }
}

void StoreDataInArray(fstream& file) {
    string arr[300];
    int i = 0;
    while (!file.eof()) {
        string line = "";
        getline(file, line);
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                line[i] = ' ';
            }
        }
        arr[i] = line;
        i++;
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << arr[i];
    }

    // Store data of each column in a separate array
    // #,claim_status,video_id,video_duration_sec,video_transcription_text,verified_status,author_ban_status,video_view_count,video_like_count,video_share_count,video_download_count,video_comment_count
    string claim_status[300];
    string video_id[300];
    string video_duration_sec[300];
    string video_transcription_text[300];
    string verified_status[300];
    string author_ban_status[300];
    string video_view_count[300];
    string video_like_count[300];
    string video_share_count[300];
    string video_download_count[300];
    string video_comment_count[300];


    for (int i = 0; i < 300; i++) {
        if (i == 299) {
            return;
        }
        int j = 0;
        while (arr[i][j] != ' ') {
            claim_status[i] += arr[i][j];
            j++;
        }
        j++;
        while (arr[i][j] != ' ') {
            video_id[i] += arr[i][j];
            j++;
        }
        j++;
        while (arr[i][j] != ' ') {
            video_duration_sec[i] += arr[i][j];
            j++;
        }
        j++;
        while (arr[i][j] != ' ') {
            video_transcription_text[i] += arr[i][j];
            j++;
        }
        j++;
        while (arr[i][j] != ' ') {
            verified_status[i] += arr[i][j];
            j++;
        }
        j++;
        if (j < strlen(arr[i]))
        { // check if j is within bounds
            while (arr[i][j] != ' ')
            {
                author_ban_status[i] += arr[i][j];
                j++;
                if (j >= strlen(arr[i]))
                { // check if j is within bounds
                    break;
                }
            }
        }
        j++;
        while (arr[i][j] != ' ')
        {
            video_view_count[i] += arr[i][j];
            j++;
        }
        j++;
        while (arr[i][j] != ' ')
        {
            video_like_count[i] += arr[i][j];
            j++;
        }
        j++;
        while (arr[i][j] != ' ')
        {
            video_share_count[i] += arr[i][j];
            j++;
        }
        j++;
        while (arr[i][j] != ' ') {
            video_download_count[i] += arr[i][j];
            j++;
        }
        j++;
        while (arr[i][j] != ' ' ) {
            video_comment_count[i] += arr[i][j];
            j++;
        }
    }

    // Display data of each column
    for (int i = 0; i < 300; i++) {
        cout << endl << claim_status[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << video_id[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << video_duration_sec[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << video_transcription_text[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << verified_status[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << author_ban_status[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << video_view_count[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << video_like_count[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << video_share_count[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << video_download_count[i];
    }
    for (int i = 0; i < 300; i++) {
        cout << endl << video_comment_count[i];
    }
}

int main() {

    fstream file;
    file.open("tiktok_dataset.csv");
    if (!file.is_open()) {
        cout << endl << "Masla";
        exit(1);
    }
    displayFileData(file);
    // StoreDataInArray(file);
    file.close();

    return 0;
}