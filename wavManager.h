#ifndef WAVMANAGER
#define WAVMANAGER

#include <fstream>
#include <vector>

typedef struct wav_header { 
// RIFF Header 
    char riff_header[4]; // Contains "RIFF" 
    int wav_size; // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8 
    char  wave_header[4]; // Contains "WAVE" 
// Format Header 
    char fmt_header[4]; // Contains "fmt " (includes trailing space) 
    int fmt_chunk_size; // Should be 16 for PCM 
    short audio_format; // Should be 1 for PCM. 3 for IEEE Float 
    short num_channels; 
    int sample_rate; 
    int byte_rate; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample 
    short sample_alignment; // num_channels * Bytes Per Sample 
    short bit_depth; // Number of bits per sample 
// Data 
    char data_header[4]; // Contains "data" 
    int data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size 
// char bytes[]; // Remainder of wave file is bytes 
} wav_header;


/**
 * @brief The WavManager class is in charge of getting and setting parts of the wav file. 
 * Additionally, it handles reading and writing wav files.
 * 
 */
class WavManager{
    private:
        wav_header wavHeader;
        std::vector<float> soundData;
    public:
        WavManager() = default;
        /**
         * @brief readFile creates an input stream to store the header, and if the file is a wav file, it will 
         * store the sound data and convert the data to be between -1 & 1. Returns 1 if file is successfully read, else 0
         * 
         * @param fileName Name of the file to be read from
         * @return int 
         */
        int readFile(const std::string &fileName);
        /**
         * @brief writeFile creates an output stream to write the header and data into a wav file.
         * It detects the bit depth and converts the data to 8 bit or 16 bit accordingly. This data is added to a buffer which
         * is then written to a file with the specified name.
         * 
         * @param newFileName Name of the file to be created/modified by the process.
         */
        void writeFile(const std::string &newFileName);
        /**
         * @brief Get the Header object
         * 
         * @return wav_header 
         */
        wav_header getHeader() const;
        /**
         * @brief Get the Data object
         * 
         * @return std::vector<float> 
         */
        std::vector<float> getData() const;
        /**
         * @brief Get the Num Channels object
         * 
         * @return int 
         */
        int getNumChannels() const;
        /**
         * @brief updateSoundData updates the data bytes and wav size in the header when echo is used. 
         * The function also expands the vector soundData if echo adds more samples.
         * 
         * @param newData New data that needs to be copied to SoundData
         */
        void updateSoundData(std::vector<float> newData);
};
#endif