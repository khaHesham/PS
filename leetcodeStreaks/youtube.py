import youtube_dl
import os

def download_playlist(url, directory_path):
    ydl_opts = {
        'format': 'bestvideo[height<=720]+bestaudio/best[height<=720]',
        'outtmpl': os.path.join(directory_path, '%(title)s.%(ext)s'),
    }
    with youtube_dl.YoutubeDL(ydl_opts) as ydl:
        ydl.download([url])

if __name__ == "__main__":
    playlist_url = input("Enter the URL of the YouTube playlist: ")
    directory_path = input("Enter the directory path to save the videos: ")
    download_playlist(playlist_url, directory_path)
