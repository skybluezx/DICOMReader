//
//  dicom_reader.h
//  DICOMReader
//
//	DICOM文件的解析工具	
//
//  Created by Zhai Xiao on 16/3/30.
//  Copyright © 2016年 ZhaiXiao. All rights reserved.
//

#pragma once; 

//该宏完成在dll项目内部使用__declspec(dllexport)导出 
//在dll项目外部使用时，用__declspec(dllimport)导入 
//宏DLL_IMPLEMENT在simpledll.cpp中定义 

#ifdef DLL_IMPLEMENT 
#define DLL_API __declspec(dllexport) 
#else 
#define DLL_API __declspec(dllimport) 
#endif 

#include <string>
#include <map>

#include "dicom_dictionary_item.h"
#include "dicom_file.h"

namespace DICOM
{ 
	//导出类 
	class DLL_API DICOMReader
	{ 
		public: 
        
        //构造方法（指定数据字典）
        DICOMReader(std::string dictionaryFileName);
		
		//读取DICOM文件
        bool read(std::string fileName);
		
		//获得DICOM文件的编码方式（是否为小端序）
        bool getEndian();
        
        //获得DICOM文件中的元素值（返回string）
        bool getValue(std::string groupNumber, std::string elementNumber, std::string& value);
        
        //获得DICOM文件中的元素值（返回unsigned short）
        bool getValue(std::string groupNumber, std::string elementNumber, unsigned short& value);
        
        //获得DICOM文件中的元素值（返回float）
        bool getValue(std::string groupNumber, std::string elementNumber, float& value);
        
        //获得DICOM文件中的元素值（返回double）
        bool getValue(std::string groupNumber, std::string elementNumber, double& value);
        
        //获得DICOM文件中的元素值（返回字节数组和数组长度）
        bool getValue(std::string groupNumber, std::string elementNumber, unsigned char*& bytes, unsigned long int& bytesLength);
        
        //关闭DICOMReader
        void close();

		private:
        
        void loadDictionary();
        
    private:
        
        std::string* dictionaryFileName;
        std::map<std::string, DictionaryItem*>* dictionary;
        std::map<std::string, int>* dictionaryItemIDList;
        
        DICOMFile* file;
        
        void loadDictionaryItemIDList();
	};
} 
