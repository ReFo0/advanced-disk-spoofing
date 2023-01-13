#pragma once
#include <ntddk.h>

extern "C" POBJECT_TYPE * IoDriverObjectType;
extern "C" NTSYSAPI NTSTATUS NTAPI ObReferenceObjectByName(PUNICODE_STRING ObjectPath, ULONG Attributes, PACCESS_STATE PassedAccessState, ACCESS_MASK DesiredAccess, POBJECT_TYPE ObjectType, KPROCESSOR_MODE AccessMode, PVOID ParseContext, PVOID * ObjectPtr);