if __name__ == "__main__":
    words = dict()
    words["otro"] = "other"
    result = words.get("test", "doesn't have")
    print(result)